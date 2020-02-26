#include "Tema1.h"

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"
#define PI 3.14159265359
using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void makeCircle(int n, int v[][2], double x, double y, double r)
{
	double u = 2 * (double)(PI / (n + 1) );
	int i;
	double a, b;
	for (i = 0; i <= n; i++)
	{
		a = cos(u * i) * r;
		b = sin(u * i) * r;
		v[i][0] = a;
		v[i][1] = b;
		
	}
}




void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	lenY = resolution.y;
	lenX = resolution.x;
	for (int i = 0; i < lenX / rectWidth + 2; i++)
		posRectX[i] = lenX + i * rectWidth;
	posRectY[1] = (rand() % lenY) / 2;
	for (int i = 1; i < lenX / rectWidth + 2; i++)
	{
		posRectYDown[i] = 0;
		while (1)
		{
			posRectY[i] = (rand() % lenY) / 2;
			if (i != lenX / rectWidth + 1)
			{
				if (abs(posRectY[i] - posRectY[i - 1]) < 100) //HAARDCODATA DISTANTA DINTRE INALTIMEA A 2 DREPTUNGHIURI CONSEC
					break;
			}
			else
			{
				if (abs(posRectY[i] - posRectY[i - 1]) < 100 &&
					abs(posRectY[i] - posRectY[0]) < 100) //HAARDCODATA DISTANTA DINTRE INALTIMEA A 2 DREPTUNGHIURI CONSEC
					break;
			}

		}

	}
	pos5RectX = posRectX[5];
	pos5RectY = posRectY[5]; //  idee neimplementata inca
	angle = 0;
	X = 250;
	Y = 300;
	speed = 1;
	int v[101][2];
	int eye[30][2];
	int cenX = 200;
	int	cenY = 200;
	int R = 50;
	makeCircle(11, v, cenX, cenY, R);
	makeCircle(11, eye, cenX, cenY, 7);


	cenX = cenY = 0;

	vector<VertexFormat> vertices
	{
		VertexFormat(glm::vec3(cenX, cenY,  0), glm::vec3(111, 0, 0)),

		VertexFormat(glm::vec3(v[0][0], v[0][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[1][0], v[1][1], 0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[2][0], v[2][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[3][0], v[3][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[4][0], v[4][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[5][0], v[5][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[6][0], v[6][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[7][0], v[7][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[8][0], v[8][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[9][0], v[9][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[10][0], v[10][1],  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(v[11][0], v[11][1],  0), glm::vec3(1, 0, 0))


	};

	vector<VertexFormat> vert_eye
	{
		VertexFormat(glm::vec3(cenX, cenY,  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[0][0], eye[0][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[1][0], eye[1][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[2][0], eye[2][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[3][0], eye[3][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[4][0], eye[4][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[5][0], eye[5][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[6][0], eye[6][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[7][0], eye[7][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[8][0], eye[8][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[9][0], eye[9][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[10][0], eye[10][1],  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(eye[11][0], eye[11][1],  0), glm::vec3(1, 1, 1))
	};

	vector<VertexFormat> vert_beak
	{
		VertexFormat(glm::vec3(cenX, cenY, 0), glm::vec3((float)244/255, (float)252/255, (float)3/255)),
		VertexFormat(glm::vec3(cenX + 60 * 0.7, cenY + 15 * 0.7, 0), glm::vec3((float)244 / 255, (float)252 / 255, (float)3 / 255)),
		VertexFormat(glm::vec3(cenX, cenY + 30 * 0.7, 0), glm::vec3((float)244 / 255, (float)252 / 255, (float)3 / 255))
	};
	vector<unsigned short> indices_beak =
	{
		1, 0, 2
	};

	vector<unsigned short> indices =
	{
		0, 1, 2, 
		0, 2, 3, 
		0, 3, 4,
		0, 4, 5,
		0, 5, 6,
		0, 6, 7,
		0, 7, 8,
		0, 8, 9,
		0, 9, 10,
		0, 10, 11,
		0, 11, 12,
		0, 12, 1
	};

	Mesh *circle1 = new Mesh("cercul1");
	circle1->InitFromData(vertices, indices);
	AddMeshToList(circle1);  // corp

	Mesh* eye_mesh = new Mesh("eye");
	eye_mesh->InitFromData(vert_eye, indices);
	AddMeshToList(eye_mesh);

	Mesh* beak = new Mesh("beak");
	beak->InitFromData(vert_beak, indices_beak);
	AddMeshToList(beak);
	
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;

	Mesh* square2 = Object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square2);

}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}



void Tema1 ::Update(float deltaTimeSeconds)
{
	if (crashed == 1)
	{
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(X, Y);
		modelMatrix *= Transform2D::Rotate(angle);
		modelMatrix *= Transform2D::Translate(-X, -Y);
		modelMatrix *= Transform2D::Translate(X + 25, Y - 15);
		RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(X, Y);
		modelMatrix *= Transform2D::Rotate(angle);
		modelMatrix *= Transform2D::Translate(-X, -Y);

		modelMatrix *= Transform2D::Translate(X + 20, Y + 20);

		RenderMesh2D(meshes["eye"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(X, Y);
		modelMatrix *= Transform2D::Rotate(angle);
		RenderMesh2D(meshes["cercul1"], shaders["VertexColor"], modelMatrix);

		for (int i = 0; i < lenX / rectWidth + 2; i++)
		{
			if (i % 2 == 0)continue;
			if (posRectX[i] <= -rectWidth)
			{
				posRectX[i] = lenX + rectWidth - (lenX - rectWidth * (lenX / rectWidth));
			}
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(posRectX[i], 0);
			modelMatrix *= Transform2D::Scale(1, (float)(lenY - posRectY[i] - 250) / rectWidth);
			RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(posRectX[i], lenY - posRectY[i]);
			modelMatrix *= Transform2D::Scale(1, 8);
			RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
		}

	}
	else
	{

		Y -= speed * deltaTimeSeconds * 60;
		if (score != 0 && score % 3 == 0 && okToIncrease)
		{
			speedIncrement += 1;
			okToIncrease = false;
		}
		if (score % 3 != 0)
			okToIncrease = true;
		speed += 0.1;
		if (speed < 0)
			speed += 2;
		if (angle > -PI / 2)
			angle -= PI / 180;
		if (angle > PI/6)
			angle = PI/6;



		timp += deltaTimeSeconds * 5;



		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(X, Y);
		modelMatrix *= Transform2D::Rotate(angle);
		modelMatrix *= Transform2D::Translate(-X, -Y);
		modelMatrix *= Transform2D::Translate(X + 25, Y - 15);
		RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(X, Y);
		modelMatrix *= Transform2D::Rotate(angle);
		modelMatrix *= Transform2D::Translate( 20,  20);


		RenderMesh2D(meshes["eye"], shaders["VertexColor"], modelMatrix);


		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(X, Y);
		modelMatrix *= Transform2D::Rotate(angle);
		RenderMesh2D(meshes["cercul1"], shaders["VertexColor"], modelMatrix);



		modelMatrix = glm::mat3(1);

		for (int i = 0; i < lenX / rectWidth + 2; i++)
		{
			if (i % 2 == 0) {
				 continue;
				}
			if (posRectX[i] <= -rectWidth)
			{
				posRectX[i] = lenX + rectWidth - (lenX - rectWidth * (lenX / rectWidth));
				passed[i] = 0;
			}
			if (passed[i] == 0 && posRectX[i] <= X)
			{
				score++;
				printf("%d\n", score);
				passed[i] = 1;

			}
			if (i == 5)
			{
				if (posRectY[i] < pos5RectY - 50)
					ok = 1;
				else if (posRectY[i] > pos5RectY)
					ok = 0;
				if (ok == 1)
					{
					posRectY[i] += 5;
					}
					
				else posRectY[i] -= 5;

			}
			posRectX[i] -= speedIncrement;
			int yRect = lenY - posRectY[i] - 250;


			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(posRectX[i], 0);
			modelMatrix *= Transform2D::Scale(1, (float)(lenY - posRectY[i] - 250) / rectWidth);
			RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

			modelMatrix = glm::mat3(1);

			modelMatrix *= Transform2D::Translate(posRectX[i], lenY - posRectY[i]);
			modelMatrix *= Transform2D::Scale(1, 8);
			RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
	}
		for (int i = 0; i < lenX / rectWidth + 2; i++)
		{
			if (i % 2 == 0)
				continue;

			if((collision(X, Y, posRectX[i], 0, posRectX[i] + 100, lenY - posRectY[i] - 250)) ||
				collision(X, Y, posRectX[i], lenY - posRectY[i], posRectX[i]+100, lenY))
			{
				printf("Your final score is %d\n", score);
				crashed = 1;
				break;
			}

		}

		if (Y <= 50) {
			printf("Your final score is %d\n", score);
			crashed = 1;
		}
	}
	

}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{

}

void Tema1::OnKeyPress(int key, int mods)
{
	// add key press event
	if (key == GLFW_KEY_SPACE && crashed != 1)
	{
		if(speed > -1)
			speed -= 20;
		if (angle < 0)
			angle += PI / 3;
	}
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}

bool Tema1::collision(int cx, int cy, int rx1, int ry1, int rx2, int ry2)
{
	int midx = (rx1 + rx2) / 2, w = abs(rx1 - rx2);
	int midy = (ry1 + ry2) / 2, h = abs(ry1 - ry2);
	int px, py;
	if (cx - midx >= 0)
		px = std::min(cx - midx, w / 2);
	else px = -1 * std::min(midx - cx, w / 2);
	if (cy - midy >= 0)
		py = std::min(cy - midy, h / 2);
	else py = -1 * std::min(midy - cy, h / 2);
	px += midx;
	py += midy;
	if ((cx - px) * (cx - px) + (cy - py) * (cy - py) < 2500)
		return true;
	return false;
}
