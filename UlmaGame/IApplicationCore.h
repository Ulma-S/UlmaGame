#pragma once
#include <functional>

namespace UlmaEngine {
	namespace Core {
		//�Q�[�����[�v�̃R�A��񋟂���C���^�[�t�F�[�X
		class IApplicationCore {
		public:
			virtual ~IApplicationCore() = default;

			//���������\�b�h (Unity��Start���\�b�h�I�Ȋ���)
			virtual bool Initialize(class IWindow& window, const std::function<void()>& registerTextureFunc, const std::function<void()>& registerSceneFunc) = 0;

			//���[�v���\�b�h (Unity��Update���\�b�h�I�Ȋ���)
			virtual void Update() = 0;

			//�I������
			virtual void Finalize() = 0;
		};
	}
}