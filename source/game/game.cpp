#include "game.hpp"


namespace game {


Game::Game() { }


void Game::Init(SDL_Renderer* renderer) {
	// Initialize Box2D
	b2Vec2 gravity(0.0f, 20.0f);
	world = new b2World(gravity);
	velocity_iterations = 6;
	position_iterations = 2;

	// Debug drawing for Box2D
	// utils::DrawBox2d draw_box2d;
	// draw_box2d.renderer = renderer;
	// draw_box2d.SetFlags(b2Draw::e_shapeBit);
	// world.SetDebugDraw(&draw_box2d);

	// Define the ground body
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 9.0f);
	groundBody = world->CreateBody(&groundBodyDef);

	// Define the ground box
	b2PolygonShape groundBox;
	groundBox.SetAsBox(SCREEN_WIDTH / 2.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the left wall body
	b2BodyDef wallLeftBodyDef;
	wallLeftBodyDef.position.Set(10.0f, SCREEN_HEIGHT / 2.0f);
	wallLeftBody = world->CreateBody(&wallLeftBodyDef);

	// Define the left wall box
	b2PolygonShape wallLeftBox;
	wallLeftBox.SetAsBox(10.0f, SCREEN_HEIGHT / 2.0f);
	wallLeftBody->CreateFixture(&wallLeftBox, 0.0f);

	// Define the right wall body
	b2BodyDef wallRightBodyDef;
	wallRightBodyDef.position.Set(SCREEN_WIDTH - 9.0f, SCREEN_HEIGHT / 2.0f);
	wallRightBody = world->CreateBody(&wallRightBodyDef);

	// Define the right wall box
	b2PolygonShape wallRightBox;
	wallRightBox.SetAsBox(10.0f, SCREEN_HEIGHT / 2.0f);
	wallRightBody->CreateFixture(&wallRightBox, 0.0f);

	// Define the ceiling body
	b2BodyDef ceilingBodyDef;
	ceilingBodyDef.position.Set(SCREEN_WIDTH / 2.0f, 10.0f);
	ceilingBody = world->CreateBody(&ceilingBodyDef);

	// Define the ceiling box
	b2PolygonShape ceilingBox;
	ceilingBox.SetAsBox(SCREEN_WIDTH / 2.0f, 10.0f);
	ceilingBody->CreateFixture(&ceilingBox, 0.0f);

	// Define the dynamic body
	b2BodyDef dynamicBodyDef;
	dynamicBodyDef.type = b2_dynamicBody;
	dynamicBodyDef.position.Set(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	dynamicBody = world->CreateBody(&dynamicBodyDef);

	// Define another box shape for our dynamic body
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(5.0f, 5.0f);

	// Define the dynamic body fixture
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.5f;
	fixtureDef.friction = 1.0f;
	dynamicBody->CreateFixture(&fixtureDef);
}


void Game::Update(float delta_seconds, input::Input input) {
	world->Step(delta_seconds, velocity_iterations, position_iterations);

	if (input.gamepads[0].button_a.pressed) {
		dynamicBody->ApplyLinearImpulseToCenter(b2Vec2(0, -10000), true);
	}

	if (input.gamepads[0].button_b.pressed) {
		dynamicBody->ApplyAngularImpulse(20000, true);
	}

	if (input.gamepads[0].stick_left.magnitude) {
		dynamicBody->ApplyLinearImpulseToCenter(b2Vec2(input.gamepads[0].stick_left.x.value * 100.0f, 0), true);
	}
}


void Game::Render(SDL_Renderer* renderer) {
	// SDL_SetRenderDrawColor(renderer, 0xDD, 0x11, 0x33, 0xFF);
	// world.DebugDraw();  // Stub that currently does nothing

	SDL_SetRenderDrawColor(renderer, 0xDD, 0x11, 0x33, 0xFF);
	SDL_Rect box_rect = SDL_Rect();
	box_rect.x = dynamicBody->GetFixtureList()->GetAABB(0).lowerBound.x;
	box_rect.y = dynamicBody->GetFixtureList()->GetAABB(0).lowerBound.y;
	box_rect.w = (dynamicBody->GetFixtureList()->GetAABB(0).upperBound.x - dynamicBody->GetFixtureList()->GetAABB(0).lowerBound.x);
	box_rect.h = (dynamicBody->GetFixtureList()->GetAABB(0).upperBound.y - dynamicBody->GetFixtureList()->GetAABB(0).lowerBound.y);
	SDL_RenderDrawRect(renderer, &box_rect);

	SDL_SetRenderDrawColor(renderer, 0x11, 0xDD, 0x33, 0xFF);
	SDL_Rect bounding_box_rect = SDL_Rect();
	bounding_box_rect.x = groundBody->GetFixtureList()->GetAABB(0).lowerBound.x;
	bounding_box_rect.y = groundBody->GetFixtureList()->GetAABB(0).lowerBound.y;
	bounding_box_rect.w = (groundBody->GetFixtureList()->GetAABB(0).upperBound.x - groundBody->GetFixtureList()->GetAABB(0).lowerBound.x);
	bounding_box_rect.h = (groundBody->GetFixtureList()->GetAABB(0).upperBound.y - groundBody->GetFixtureList()->GetAABB(0).lowerBound.y);
	SDL_RenderDrawRect(renderer, &bounding_box_rect);
	bounding_box_rect.x = wallLeftBody->GetFixtureList()->GetAABB(0).lowerBound.x;
	bounding_box_rect.y = wallLeftBody->GetFixtureList()->GetAABB(0).lowerBound.y;
	bounding_box_rect.w = (wallLeftBody->GetFixtureList()->GetAABB(0).upperBound.x - wallLeftBody->GetFixtureList()->GetAABB(0).lowerBound.x);
	bounding_box_rect.h = (wallLeftBody->GetFixtureList()->GetAABB(0).upperBound.y - wallLeftBody->GetFixtureList()->GetAABB(0).lowerBound.y);
	SDL_RenderDrawRect(renderer, &bounding_box_rect);
	bounding_box_rect.x = wallRightBody->GetFixtureList()->GetAABB(0).lowerBound.x;
	bounding_box_rect.y = wallRightBody->GetFixtureList()->GetAABB(0).lowerBound.y;
	bounding_box_rect.w = (wallRightBody->GetFixtureList()->GetAABB(0).upperBound.x - wallRightBody->GetFixtureList()->GetAABB(0).lowerBound.x);
	bounding_box_rect.h = (wallRightBody->GetFixtureList()->GetAABB(0).upperBound.y - wallRightBody->GetFixtureList()->GetAABB(0).lowerBound.y);
	SDL_RenderDrawRect(renderer, &bounding_box_rect);
	bounding_box_rect.x = ceilingBody->GetFixtureList()->GetAABB(0).lowerBound.x;
	bounding_box_rect.y = ceilingBody->GetFixtureList()->GetAABB(0).lowerBound.y;
	bounding_box_rect.w = (ceilingBody->GetFixtureList()->GetAABB(0).upperBound.x - ceilingBody->GetFixtureList()->GetAABB(0).lowerBound.x);
	bounding_box_rect.h = (ceilingBody->GetFixtureList()->GetAABB(0).upperBound.y - ceilingBody->GetFixtureList()->GetAABB(0).lowerBound.y);
	SDL_RenderDrawRect(renderer, &bounding_box_rect);
}


}	// namespace game
