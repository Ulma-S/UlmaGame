#pragma once

namespace System {
	namespace Core {
		//�O���t�B�b�N�XAPI�ɉ������E�B���h�E�N���X
		//����Hogewindow�^�̎Q�Ƃق����Ȃ邵�A���̃C���^�[�t�F�[�X�̈Ӗ�����̂��s��
		class IWindow {
		public:
			virtual ~IWindow() = default;

			virtual bool CreateWindow() = 0;
			virtual void Finalize() = 0;

			virtual bool CanLoop() = 0;

			virtual int GetWindowWidth() const = 0;
			virtual int GetWindowHeight() const = 0;
		};
	}
}