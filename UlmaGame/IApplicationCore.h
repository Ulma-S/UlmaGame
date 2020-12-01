#pragma once

namespace System {
	namespace Core {
		//ゲームループのコアを提供するインターフェース
		class IApplicationCore {
		public:
			virtual ~IApplicationCore() = default;

			//初期化メソッド (UnityのStartメソッド的な感じ)
			virtual bool Initialize(class IWindow& window) = 0;

			//ループメソッド (UnityのUpdateメソッド的な感じ)
			virtual void Update() = 0;

			//終了処理
			virtual void Finalize() = 0;
		};
	}
}