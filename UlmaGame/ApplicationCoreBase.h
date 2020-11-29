#pragma once

//�Q�[�����[�v�̃R�A��񋟂���C���^�[�t�F�[�X
class IApplicationCore {
public:
	virtual ~IApplicationCore() = default;
	
	//���������\�b�h (Unity��Start���\�b�h�I�Ȋ���)
	virtual bool Initialize() = 0;

	//���[�v���\�b�h (Unity��Update���\�b�h�I�Ȋ���)
	virtual void Update() = 0;

	//�I������
	virtual void Finalize() = 0;

	virtual void AddActor(class Actor& actor) = 0;

	virtual void RemoveActor(class Actor& actor) = 0;
};