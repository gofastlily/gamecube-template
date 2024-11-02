#include "game.hpp"


namespace game {


Game::Game() { }


void Game::Init(SDL_Renderer* renderer) {
	// Initialize Box2D
	b2Vec2 gravity(0.0f, 24.0f);
	world = new b2World(gravity);
	velocity_iterations = 6;
	position_iterations = 2;
	world_height = 24.0f;	// meters?
	world_width = 32.0f;	// meters?
	world_rendering_scale = 20.0f;

	// Debug drawing for Box2D
	// utils::DrawBox2d draw_box2d = utils::DrawBox2d();
	// draw_box2d.renderer = renderer;
	// draw_box2d.pixels_per_meter = world_rendering_scale;
	// draw_box2d.SetFlags(b2Draw::e_shapeBit);
	// world->SetDebugDraw(&draw_box2d);

	// Define the ground body
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(world_width / 2.0f, world_height - 1.0f);
	groundBody = world->CreateBody(&groundBodyDef);

	// Define the ground box
	b2PolygonShape groundBox;
	groundBox.SetAsBox(world_width / 2.0f, 1.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the left wall body
	b2BodyDef wallLeftBodyDef;
	wallLeftBodyDef.position.Set(1.0f, world_height / 2.0f);
	wallLeftBody = world->CreateBody(&wallLeftBodyDef);

	// Define the left wall box
	b2PolygonShape wallLeftBox;
	wallLeftBox.SetAsBox(1.0f, world_height / 2.0f);
	wallLeftBody->CreateFixture(&wallLeftBox, 0.0f);

	// Define the right wall body
	b2BodyDef wallRightBodyDef;
	wallRightBodyDef.position.Set(world_width - 1.0f, world_height / 2.0f);
	wallRightBody = world->CreateBody(&wallRightBodyDef);

	// Define the right wall box
	b2PolygonShape wallRightBox;
	wallRightBox.SetAsBox(1.0f, world_height / 2.0f);
	wallRightBody->CreateFixture(&wallRightBox, 0.0f);

	// Define the ceiling body
	b2BodyDef ceilingBodyDef;
	ceilingBodyDef.position.Set(world_width / 2.0f, 1.0f);
	ceilingBody = world->CreateBody(&ceilingBodyDef);

	// Define the ceiling box
	b2PolygonShape ceilingBox;
	ceilingBox.SetAsBox(world_width / 2.0f, 1.0f);
	ceilingBody->CreateFixture(&ceilingBox, 0.0f);

	// Define the dynamic body
	b2BodyDef characterBodyDef;
	characterBodyDef.type = b2_dynamicBody;
	characterBodyDef.position.Set(world_width / 2.0f, world_height / 2.0f);
	characterBody = world->CreateBody(&characterBodyDef);

	// Define the base box for our character body
	b2PolygonShape characterBodyBox;
	characterBodyBox.SetAsBox(0.5666f, 0.5666f);  // 1.7f total height

	// Define the base body fixture
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &characterBodyBox;
	fixtureDef.density = 5.0f;
	fixtureDef.friction = 1.0f;
	characterBody->CreateFixture(&fixtureDef);

	// Define the upper body for character
	characterBodyBox.SetAsBox(0.5666f, 1.7f - 0.5666f);  // 1.7f total height
	fixtureDef.shape = &characterBodyBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;
	characterBody->CreateFixture(&fixtureDef);
}


void Game::Update(float delta_seconds, input::Input input) {
	world->Step(delta_seconds, velocity_iterations, position_iterations);

	if (input.gamepads[0].button_a.pressed) {
		characterBody->ApplyLinearImpulseToCenter(b2Vec2(0, -100), true);
	}

	if (input.gamepads[0].stick_left.magnitude) {
		characterBody->ApplyLinearImpulseToCenter(b2Vec2(input.gamepads[0].stick_left.x.value * 2.0f, 0), true);
	}
}


void Game::Render(SDL_Renderer* renderer) {
	world->DebugDraw();

	// SDL_SetRenderDrawColor(renderer, 0xAA, 0x11, 0x33, 0xFF);
	// RenderBoundingBox(renderer, characterBody);

	// SDL_SetRenderDrawColor(renderer, 0x11, 0xDD, 0x33, 0xFF);
	// RenderBoundingBox(renderer, groundBody);
	// RenderBoundingBox(renderer, wallLeftBody);
	// RenderBoundingBox(renderer, wallRightBody);
	// RenderBoundingBox(renderer, ceilingBody);
}


void Game::RenderBoundingBox(SDL_Renderer* renderer, b2Body* body) {
	SDL_Rect bounding_box_rect = SDL_Rect();
	bounding_box_rect.x = body->GetFixtureList()->GetAABB(0).lowerBound.x * world_rendering_scale;
	bounding_box_rect.y = body->GetFixtureList()->GetAABB(0).lowerBound.y * world_rendering_scale;
	bounding_box_rect.w = (body->GetFixtureList()->GetAABB(0).upperBound.x - body->GetFixtureList()->GetAABB(0).lowerBound.x) * world_rendering_scale;
	bounding_box_rect.h = (body->GetFixtureList()->GetAABB(0).upperBound.y - body->GetFixtureList()->GetAABB(0).lowerBound.y) * world_rendering_scale;
	SDL_RenderDrawRect(renderer, &bounding_box_rect);
}


}	// namespace game
