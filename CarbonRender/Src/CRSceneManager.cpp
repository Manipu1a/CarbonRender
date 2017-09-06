#include "..\Inc\CRSceneManager.h"

SceneManager* SceneManager::ins = nullptr;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

SceneManager * SceneManager::Instance()
{
	if (ins == nullptr)
		ins = new SceneManager();

	return ins;
}

void SceneManager::Init()
{
}

void SceneManager::LoadScene()
{
	Camera cam;
	cam.SetPerspectiveCamera(60.0f, 0.01f, 3000.0f);
	cam.SetPosition(float3(0.0f, 2.0f, 0.0f));
	CameraManager::Instance()->Push(cam);

	Controller ctrl;
	ctrl.Init();
	ControllerManager::Instance()->Push(ctrl);

	FbxImportManager::Instance()->ImportFbxModel("terrain", &terrain);
	FbxImportManager::Instance()->ImportFbxModel("Sponza", &sponza);
	FbxImportManager::Instance()->ImportFbxModel("Type59", &type59);
	terrain.GetReady4Rending();
	sponza.GetReady4Rending();
	type59.GetReady4Rending();

	sponza.SetPosition(float3(-1.0f, -0.6f, -17.5f));
	sponza.SetRotation(float3(0.0f, 180.0f, 0.0f));
	type59.SetPosition(float3(-1.0f, -0.6f, -17.5f));
	type59.SetRotation(float3(0.0f, 0.0f, 0.0f));
}

void SceneManager::DrawScene(GLuint shaderProgram)
{
	terrain.Render(shaderProgram);
	sponza.Render(shaderProgram);
	type59.Render(shaderProgram);
}
