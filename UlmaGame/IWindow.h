#pragma once

namespace UlmaEngine {
	namespace Core {
		//グラフィックスAPIに応じたウィンドウクラス
		//結局Hogewindow型の参照ほしくなるし、このインターフェースの意味あるのか不明
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
			virtual float GetScale() const = 0;	//ワールド座標系における1に対応する画素数
		};
	}
}