#pragma once

#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include "Structures.h"
#include "Vector3D.h"

using namespace DirectX;

class Camera
{
private:
	XMFLOAT3 _eye; 
	XMFLOAT3 _at;
	XMFLOAT3 _up;
	XMFLOAT3 _right = XMFLOAT3(1, 0, 0);

	FLOAT _windowWidth;
	FLOAT _windowHeight;
	FLOAT _nearDepth;
	FLOAT _farDepth;

	XMFLOAT4X4 _view;
	XMFLOAT4X4 _projection;

	std::string m_Name;

public:
	Camera(XMFLOAT3 position, XMFLOAT3 at, XMFLOAT3 up, FLOAT windowWidth, FLOAT windowHeight, FLOAT nearDepth, FLOAT farDepth);
	~Camera();

	void Update();

	XMFLOAT4X4 GetView() const { return _view; }
	XMFLOAT4X4 GetProjection() const { return _projection; }

	XMFLOAT4X4 GetViewProjection() const;

	XMFLOAT3 GetPosition() const { return _eye; }
	XMFLOAT3 GetLookAt() const { return _at; }
	XMFLOAT3 GetUp() const { return _up; }
	XMFLOAT3 GetRight() { return _right; };
	std::string GetName() { return m_Name; };

	void SetPosition(XMFLOAT3 position) { _eye = position; }
	void SetLookAt(XMFLOAT3 lookAt) { _at = lookAt; }
	void SetUp(XMFLOAT3 up) { _up = up; }
	void SetRight(XMFLOAT3 Right) { _right = Right; };
	void Reshape(FLOAT windowWidth, FLOAT windowHeight, FLOAT nearDepth, FLOAT farDepth);
	void SetName(std::string s) { m_Name = s; };

	//Movement//

//Takes the mouse input and makes it useful to the class
	void ManageMouseMovement(MouseData MD);


	//Moves the Camera along the Z vector
	void Walk(float Direction);
	//Moves the Camera along the Z vector
	void Strafe(float Direction);
	//Rotates the Camera on the X axis
	void Pitch(float Angle);
	//Rotates the Camera on the Y axis
	void Yaw(float Angle);

	//Lens Effects//

	//To be fixed or removed
	void Zoom();
	void Unzoom();
};

