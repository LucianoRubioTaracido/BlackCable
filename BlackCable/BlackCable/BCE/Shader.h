#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>

class Shader
{
public:
	Shader();

	void CreateFromString(const char* vertexCode, const char* fragmentCode);
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

	std::string ReadFile(const char* fileLocation);

	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	////Material
	//GLuint GetAmbientIntensityLocation();
	//GLuint GetAmbientColourLocation();
	//GLuint GetDiffuseIntensityLocation();
	//GLuint GetDirectionLocation();
	//GLuint GetSpecularIntensityLocation();
	//GLuint GetShininessLocation();
	//GLuint GetEyePositionLocation();
	
	GLuint GetMyMaterialAmbient();
	GLuint GetMyLightAmbient();

	void UseShader();
	void ClearShader();

	~Shader();

private:
	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition;
	GLuint uniformAmbientIntensity, uniformAmbientColour, uniformDiffuseIntensity, uniformDirection,
		   uniformSpecularIntensity, uniformShininess,
		   myMaterialAmbient, myLightAmbient;

	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

