#pragma once

namespace Game {
	namespace Core {
		class Collider2D {
		public:
			Collider2D();
			virtual ~Collider2D();

			bool enable;	//衝突判定が有効か？
			bool isTrigger;	//Triggerか？
		};
	}
}