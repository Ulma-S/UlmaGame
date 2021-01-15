#pragma once

namespace UlmaEngine {
	namespace Core {
		//�O���t�B�b�N�XAPI�ɉ������E�B���h�E�N���X
		//����Hogewindow�^�̎Q�Ƃق����Ȃ邵�A���̃C���^�[�t�F�[�X�̈Ӗ�����̂��s��
		class IWindow {
		public:
			virtual ~IWindow() = default;

			virtual bool CreateWindow() = 0;
			virtual void ClearDisplayBuffer() const = 0;
			virtual void SwapBuffer() const = 0;
			virtual void Finalize() const = 0;

			virtual void PollEvent() const = 0;
			virtual bool CanLoop() const = 0;
			virtual float GetCurrentTime() const = 0;

			virtual int GetWindowWidth() const = 0;
			virtual int GetWindowHeight() const = 0;
			virtual float GetScale() const = 0;	//���[���h���W�n�ɂ�����1�ɑΉ������f��
		};
	}
}