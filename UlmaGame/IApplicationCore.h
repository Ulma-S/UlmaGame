#pragma once

namespace System {
	namespace Core {
		//�Q�[�����[�v�̃R�A��񋟂���C���^�[�t�F�[�X
		class IApplicationCore {
		public:
			virtual ~IApplicationCore() = default;

			//���������\�b�h (Unity��Start���\�b�h�I�Ȋ���)
			virtual bool Initialize(class IWindow& window) = 0;

			//���[�v���\�b�h (Unity��Update���\�b�h�I�Ȋ���)
			virtual void Update() = 0;

			//�I������
			virtual void Finalize() = 0;
		};
	}
}