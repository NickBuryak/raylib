/*******************************************************************************************
*
*   raylib [models] example - Show the difference between perspective and orthographic projection 
*
*   This program is heavily based on the geometric objects example
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - geometric shapes");

    const Camera perspective_camera = (Camera){{ 0.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, CAMERA_PERSPECTIVE };
    const Camera orthographic_camera = (Camera){{ 0.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 10.0f, CAMERA_ORTHOGRAPHIC };
    // Define the camera to look into our 3d world
    Camera camera = perspective_camera;

    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        //

        // Input
        //----------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_SPACE)) 
        {
            if(camera.type == CAMERA_PERSPECTIVE) 
            {
                camera = orthographic_camera;
            } 
            else 
            {
                camera = perspective_camera;
            }
        }


        // Draw
        //----------------------------------------------------------------------------------


        BeginDrawing();

            ClearBackground(RAYWHITE);

            Begin3dMode(camera);

                DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
                DrawCubeWires((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, GOLD);
                DrawCubeWires((Vector3){-4.0f, 0.0f, -2.0f}, 3.0f, 6.0f, 2.0f, MAROON);

                DrawSphere((Vector3){-1.0f, 0.0f, -2.0f}, 1.0f, GREEN);
                DrawSphereWires((Vector3){1.0f, 0.0f, 2.0f}, 2.0f, 16, 16, LIME);

                DrawCylinder((Vector3){4.0f, 0.0f, -2.0f}, 1.0f, 2.0f, 3.0f, 4, SKYBLUE);
                DrawCylinderWires((Vector3){4.0f, 0.0f, -2.0f}, 1.0f, 2.0f, 3.0f, 4, DARKBLUE);
                DrawCylinderWires((Vector3){4.5f, -1.0f, 2.0f}, 1.0f, 1.0f, 2.0f, 6, BROWN);

                DrawCylinder((Vector3){1.0f, 0.0f, -4.0f}, 0.0f, 1.5f, 3.0f, 8, GOLD);
                DrawCylinderWires((Vector3){1.0f, 0.0f, -4.0f}, 0.0f, 1.5f, 3.0f, 8, PINK);

                DrawGrid(10, 1.0f);        // Draw a grid

            End3dMode();

            DrawFPS(10, 10);

            DrawText("Press Spacebar to switch camera type", 10, 40, 24, BLACK);

            if(camera.type == CAMERA_ORTHOGRAPHIC)
            {
                DrawText("Orthographic", 10, 65, 24, BLACK);
            }
            else if(camera.type == CAMERA_PERSPECTIVE)
            {
                DrawText("Perspective", 10, 65, 24, BLACK);
            }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
