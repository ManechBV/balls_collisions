#include "raylib.h"
#include "time.h"

#include "utils.h"
#include "ball.h"

int main(int argc, char **argv) 
{
	t_vec			window_size_vec;	//Window width and height
	t_ball_manager	ball_manager;		//Ball manager, contains chained list of t_ball

	// manage arguments, use: ./main 1600 900
	if (argc == 3)
	{
		//Resize window size vector based on arguments
		window_size_vec = ft_create_vec(atoi(argv[1]), atoi(argv[2]));
		if (window_size_vec.x > 1920 || window_size_vec.x < 100)
			window_size_vec.x = DEFAULT_WINDOW_WIDTH;
		if (window_size_vec.y > 1080 || window_size_vec.y < 100)
			window_size_vec.y = DEFAULT_WINDOW_HEIGHT;
	}
	else
		window_size_vec = ft_create_vec(800, 600);	// if no argument is given

	ft_init_ball_manager(&ball_manager);

	//Reset random seed
	SetRandomSeed((unsigned int)time(NULL));

	//Create multiples balls at random positions and sizes
	for (int i = 0; i < 10; i++)
	{
		ft_add_ball_to_chain(
			&ball_manager, 
			GetRandomValue(30, window_size_vec.x - 30), 
			GetRandomValue(30, window_size_vec.y - 30), 
			(float)GetRandomValue(10, 30)
		);
	}

	//Create window based on vector
	InitWindow(window_size_vec.x, window_size_vec.y, "aller putain");
	SetTargetFPS(60);

	//Main loop
	while (!WindowShouldClose()) 
	{
		//Update shit

		//Draw shit
		BeginDrawing();
		ClearBackground(DARKGRAY);

		ft_draw_all_balls(&ball_manager);

		EndDrawing();
	}

	//Free shit
	ft_free_ball_manager(&ball_manager);

	CloseWindow();
	return (0);
}
