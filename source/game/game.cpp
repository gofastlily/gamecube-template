#include "game.hpp"


// Standard library includes
#include <stdlib.h>
#include <string>


// Linked library includes
#include <SDL2/SDL_ttf.h>


// Local source includes
#include "constants.hpp"
#include "physics.hpp"


// Local asset includes
#include "pong_score_ttf.h"


namespace game {


Game::Game() { }


void Game::Init(SDL_Renderer* renderer) {
	paddle_left = Paddle((char*)"Left Paddle");
	paddle_left.transform.position.x = 30.0f;
	paddle_left.target_x_position = paddle_left.transform.position.x;
	paddle_left.transform.position.y = SCREEN_HEIGHT / 2.0f;
	paddle_left.maximum_velocity = 125.0f;

	paddle_right = Paddle((char*)"Right Paddle");
	paddle_right.transform.position.x = SCREEN_WIDTH - 30;
	paddle_right.target_x_position = paddle_right.transform.position.x;
	paddle_right.transform.position.y = SCREEN_HEIGHT / 2.0f;
	paddle_right.maximum_velocity = 125.0f;

	ball = Ball((char*)"Ball");
	ball.transform.position.x = SCREEN_WIDTH / 2.0f;
	ball.transform.position.y = SCREEN_HEIGHT / 2.0f;
	ball.velocity.x = 175.0f;
	ball.velocity.y = 40.0f;
	ball.maximum_velocity = 175.0f;

	SDL_RWops* score_font_raw = SDL_RWFromConstMem(pong_score_ttf, pong_score_ttf_size);
	TTF_Font* score_font = TTF_OpenFontRW(score_font_raw, 1, 50);

	score_left.renderer = renderer;
	score_left.font = score_font;
	score_left.color = SDL_Color(255, 255, 255);
	score_left.wrap_width = 150.0f;
	score_left.UpdateText("0");

	score_right.renderer = renderer;
	score_right.font = score_font;
	score_right.color = SDL_Color(255, 255, 255);
	score_right.wrap_width = 150.0f;
	score_right.UpdateText("0");
}


void Game::Update(float delta_seconds, input::Input input) {
	ball.Update(delta_seconds);


	if (input.gamepads[0].IsConnected()) {
		paddle_left.Update(delta_seconds, input.gamepads[0]);
	} else {
		AIMovePaddleLeft();
		paddle_left.Update(delta_seconds, ai_left_gamepad);
	}


	if (input.gamepads[1].IsConnected()) {
		paddle_right.Update(delta_seconds, input.gamepads[1]);
	} else {
		AIMovePaddleRight();
		paddle_right.Update(delta_seconds, ai_right_gamepad);
	}


	// Ball vs Left and Right Wall
	if (ball.transform.position.x < ball.size / 2.0f) {
		score_right.UpdateText(std::to_string(std::stoi(score_right.value.c_str()) + 1));
		ball.Reset();
	} else if (ball.transform.position.x > SCREEN_WIDTH - (ball.size / 2.0f)) {
		score_left.UpdateText(std::to_string(std::stoi(score_left.value.c_str()) + 1));
		ball.Reset();
	}


	// Ball vs Top and Bottom Wall
	if (ball.transform.position.y < (ball.size / 2.0f)) ball.velocity.y = 180.0f - ball.velocity.y;
	if (ball.transform.position.y > SCREEN_HEIGHT - (ball.size / 2.0f)) ball.velocity.y = 180.0f - ball.velocity.y;


	// Ball vs Left Paddle
	if (Physics::CheckCollisionAABB(ball.collider, paddle_left.collider)) {
		if (Physics::CheckCollisionAABB(ball.collider, paddle_left.zone_right)) {
			ball.velocity.y = -ball.PaddleCollisionAngle(paddle_left) + 90.0f;
		}
		else if (Physics::CheckCollisionAABB(ball.collider, paddle_left.zone_up)
		|| Physics::CheckCollisionAABB(ball.collider, paddle_left.zone_down)) {
			ball.velocity.y = 180 - ball.velocity.y;
		}
	}


	// Ball vs Right Paddle
	if (Physics::CheckCollisionAABB(ball.collider, paddle_right.collider)) {
		if (Physics::CheckCollisionAABB(ball.collider, paddle_right.zone_left)) {
			ball.velocity.y = ball.PaddleCollisionAngle(paddle_right) - 90.0f;
		}
		if (Physics::CheckCollisionAABB(ball.collider, paddle_right.zone_up)
		|| Physics::CheckCollisionAABB(ball.collider, paddle_right.zone_down)) {
			ball.velocity.y = 180 - ball.velocity.y;
		}
	}

	if (input.gamepads[0].button_start.pressed) {
		ball.Reset();
		score_left.UpdateText("0");
		score_right.UpdateText("0");
	}
}


void Game::Render(SDL_Renderer* renderer) {
	// Dotted center line
	SDL_SetRenderDrawColor(renderer, 0xDD, 0xDD, 0xDD, 0xFF);
	SDL_Rect midline_rect;
	midline_rect.x = SCREEN_WIDTH / 2.0f + 5;
	midline_rect.w = 11;
	midline_rect.h = 11;
	for (int i = 0; i <= SCREEN_HEIGHT; i += 26) {
		midline_rect.y = i;
		SDL_RenderFillRect(renderer, &midline_rect);
	}

	SDL_SetRenderDrawColor(renderer, 0xDD, 0xDD, 0xDD, 0xFF);
	SDL_RenderFillRect(renderer, &paddle_left.collider);

	SDL_SetRenderDrawColor(renderer, 0xDD, 0xDD, 0xDD, 0xFF);
	SDL_RenderFillRect(renderer, &paddle_right.collider);

	SDL_SetRenderDrawColor(renderer, 0xDD, 0xDD, 0xDD, 0xFF);
	SDL_RenderFillRect(renderer, &ball.collider);

	score_left.rect.x = SCREEN_WIDTH / 4.0f * 1.0f  - score_left.surface->w / 2.0f;
	score_left.rect.y = SCREEN_HEIGHT / 10.0f;
	score_left.rect.w = score_left.surface->w;
	score_left.rect.h = score_left.surface->h;
	score_left.Render();

	score_right.rect.x = SCREEN_WIDTH / 4.0f * 3.0f  - score_right.surface->w / 2.0f;
	score_right.rect.y = SCREEN_HEIGHT / 10.0f;
	score_right.rect.w = score_right.surface->w;
	score_right.rect.h = score_right.surface->h;
	score_right.Render();
}


void Game::AIMovePaddleLeft() {
	if (ball.velocity.y <= 0) {
		ai_left_gamepad.stick_left.magnitude = AIMovePaddleTowardsBall(paddle_left);
	} else {
		ai_left_gamepad.stick_left.magnitude = AIMovePaddleTowardsCenter(paddle_left);
	}
}


void Game::AIMovePaddleRight() {
	if (ball.velocity.y > 0) {
		ai_right_gamepad.stick_left.magnitude = AIMovePaddleTowardsBall(paddle_right);
	} else {
		ai_right_gamepad.stick_left.magnitude = AIMovePaddleTowardsCenter(paddle_right);
	}
}


float Game::AIMovePaddleTowardsBall(game::Paddle paddle) {
	if (ball.transform.position.y + ball.size / 2.0f > paddle.transform.position.y) {
		return -1.0f;
	} else if (ball.transform.position.y < paddle.transform.position.y - ball.size / 2.0f) {
		return 1.0f;
	}
	return 0.0f;
}


float Game::AIMovePaddleTowardsCenter(game::Paddle paddle) {
	if (paddle.transform.position.y > SCREEN_HEIGHT / 2) {
		return 1.0f;
	} else if (paddle.transform.position.y < SCREEN_HEIGHT / 2) {
		return -1.0f;
	}
	return 0.0f;
}


}	// namespace game
