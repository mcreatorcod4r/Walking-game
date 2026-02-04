#include <raylib.h>

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 720;

	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(1280, 720, "Walking Around 1.0.1");
	
	HideCursor();

	Image test = LoadImage("res/test.png");
	ImageResize(&test, 1280, 720);

	Texture2D texture = LoadTextureFromImage(test);
	UnloadImage(test);

	Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)) ballPosition.x += GetFrameTime()*2.0f;
		if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)) ballPosition.x -= GetFrameTime()*2.0f;
		if (IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)) ballPosition.y -= GetFrameTime()*2.0f;
		if (IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)) ballPosition.y += GetFrameTime()*2.0f;
		if (IsKeyDown(KEY_ESCAPE)) CloseWindow();

		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
			DrawCircleV(ballPosition, 50, ORANGE);
		EndDrawing();
	}

	UnloadTexture(texture);

	CloseWindow();

	return 0;
}