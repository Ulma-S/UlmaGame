#pragma once

namespace Game {
	namespace Core {
		class Collider2D {
		public:
			Collider2D();
			virtual ~Collider2D();

			bool enable;	//�Փ˔��肪�L�����H
			bool isTrigger;	//Trigger���H
		};
	}
}