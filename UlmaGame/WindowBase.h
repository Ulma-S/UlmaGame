#pragma once

namespace System {
	namespace Core {
		//グラフィックスAPIに応じたウィンドウクラス
		//結局Hogewindow型の参照ほしくなるし、このインターフェースの意味あるのか不明
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