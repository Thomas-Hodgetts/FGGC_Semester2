#include "Camera.h"

Camera::Camera(XMFLOAT3 position, XMFLOAT3 at, XMFLOAT3 up, FLOAT windowWidth, FLOAT windowHeight, FLOAT nearDepth, FLOAT farDepth)
	: _eye(position), _at(at), _up(up), _windowWidth(windowWidth), _windowHeight(windowHeight), _nearDepth(nearDepth), _farDepth(farDepth)
{
	Update();
}

Camera::~Camera()
{
}

void Camera::Update()
{
    // Initialize the view matrix

	XMFLOAT4 eye = XMFLOAT4(_eye.x, _eye.y, _eye.z, 1.0f);
	XMFLOAT4 at = XMFLOAT4(_at.x, _at.y, _at.z, 1.0f);
	XMFLOAT4 up = XMFLOAT4(_up.x, _up.y, _up.z, 0.0f);

	XMVECTOR EyeVector = XMLoadFloat4(&eye);
	XMVECTOR AtVector = XMLoadFloat4(&at);
	XMVECTOR UpVector = XMLoadFloat4(&up);

	XMStoreFloat4x4(&_view, XMMatrixLookAtLH(EyeVector, AtVector, UpVector));

    // Initialize the projection matrix
	XMStoreFloat4x4(&_projection, XMMatrixPerspectiveFovLH(0.25f * XM_PI, _windowWidth / _windowHeight, _nearDepth, _farDepth));
}

void Camera::Reshape(FLOAT windowWidth, FLOAT windowHeight, FLOAT nearDepth, FLOAT farDepth)
{
	_windowWidth = windowWidth;
	_windowHeight = windowHeight;
	_nearDepth = nearDepth;
	_farDepth = farDepth;
}

XMFLOAT4X4 Camera::GetViewProjection() const 
{ 
	XMMATRIX view = XMLoadFloat4x4(&_view);
	XMMATRIX projection = XMLoadFloat4x4(&_projection);

	XMFLOAT4X4 viewProj;

	XMStoreFloat4x4(&viewProj, view * projection);

	return viewProj;
}

void Camera::ManageMouseMovement(MouseData MD)
{
	float dx = XMConvertToRadians(0.05f * (MD.xPos - MD.PrevXPos));
	float dy = XMConvertToRadians(0.05f * (MD.yPos - MD.PrevYPos));
	Pitch(dy);
	Yaw(dx);
}

//Book
void Camera::Walk(float Direction)
{
	XMVECTOR Speed = XMVectorReplicate(Direction);
	XMVECTOR NewLook = XMLoadFloat3(&GetLookAt());
	XMVECTOR Pos = XMLoadFloat3(&GetPosition());
	XMStoreFloat3(&_eye, XMVectorMultiplyAdd(Speed, NewLook, Pos));
}
//Book
void Camera::Strafe(float Direction)
{
	XMVECTOR Speed = XMVectorReplicate(Direction);
	XMVECTOR Right = XMLoadFloat3(&GetRight());
	XMVECTOR Pos = XMLoadFloat3(&GetPosition());
	XMStoreFloat3(&_eye, XMVectorMultiplyAdd(Speed, Right, Pos));
}
//Book
void Camera::Pitch(float Angle)
{
	XMMATRIX Rotation = XMMatrixRotationAxis(XMLoadFloat3(&GetRight()), Angle);
	XMStoreFloat3(&_up, XMVector3TransformNormal(XMLoadFloat3(&GetUp()), Rotation));
	XMStoreFloat3(&_at, XMVector3TransformNormal(XMLoadFloat3(&GetLookAt()), Rotation));
}
//Book
void Camera::Yaw(float Angle)
{
	XMMATRIX Rotation = XMMatrixRotationY(Angle);
	XMStoreFloat3(&_right, XMVector3TransformNormal(XMLoadFloat3(&GetRight()), Rotation));
	XMStoreFloat3(&_up, XMVector3TransformNormal(XMLoadFloat3(&GetUp()), Rotation));
	XMStoreFloat3(&_at, XMVector3TransformNormal(XMLoadFloat3(&GetLookAt()), Rotation));
}