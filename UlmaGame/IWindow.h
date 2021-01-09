#pragma once

namespace UlmaEngine {
	namespace Core {
		//グラフィックスAPIに応じたウィンドウクラス
		//結局Hogewindow型の参照ほしくなるし、このインターフェースの意味あるのか不明
		class IWindow {
		public:
			virtual ~IWindow() = default;

			virtual bool CreateWindow() = 0;
			virtual void ClearDisplayBuffer() = 0;
			virtual void SwapBuffer() = 0;
			virtual void Finalize() = 0;

			virtual void PollEvent() = 0;
			virtual bool CanLoop() = 0;
			virtual float GetCurrentTime() = 0;

			virtual int GetWindowWidth() const = 0;
			virtual int GetWindowHeight() const = 0;
			virtual float GetScale() const = 0;	//ワールド座標系における1に対応する画素数
		};
	}
}