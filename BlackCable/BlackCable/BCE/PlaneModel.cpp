#include "PlaneModel.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include "ShaderManager.h"


PlaneModel::PlaneModel()
{
}


PlaneModel::~PlaneModel()
{
}

void PlaneModel::Init()
{
	LoadMesh();
	texture = new Texture("Assets/Textures/brick.png");
	texture->LoadTexture();

}

void PlaneModel::Draw()
{
	GLuint uniformModel = 0;
	uniformModel = ShaderManager::getPtr()->GetModelLocation();
	glm::mat4 model(1);
	///model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
	model = glm::scale(model, glm::vec3(4.4f, 4.4f, 4.0f));
	model = glm::rotate(model, 90.0f, glm::vec3(0, 1.0f, 0.0f));
	//angle += 0.001f;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	texture->UseTexture();
	meshList[0]->RenderMesh();
	//glUseProgram(0);
}

void PlaneModel::LoadMesh()
{
	unsigned int indices[] = {
		// front
		0,1,2,
		2,3,0,
	};

	GLfloat vertices[] = {
		-1.0, -1.0,  1.0, 0.0f, 0.0f,		0.4f, 0.0f, 0.8f,//0
		1.0, -1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,//1
		1.0,  1.0,  1.0,0.0f, 1.0f,		0.0f, 0.0f, 0.0f,//2
		-1.0,  1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,//3
	};
	calcAverageNormals(indices, 6, vertices, 32, 8, 5);

	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 6);
	meshList.push_back(obj1);
}