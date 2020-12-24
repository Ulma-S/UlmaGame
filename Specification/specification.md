# Ulma Game プログラム仕様
## クラス一覧
### 1. ウィンドウ関連

```plantuml
namespace System{
    namespace Core{
        interface IWindow{}
        class WindowOpenGL{
            //GLFWを利用したウィンドウ生成
        }
        IWindow <|.. WindowOpenGL
    }
}
```
- IWindowインターフェース
    - ウィンドウ作成
    - ダブルバッファ対応
    - イベント処理
    - 時間取得

- WindowOpenGLクラス
    - GLFW, GLEWの初期化

### 2. アプリケーション

```plantuml
namespace System{
    namespace Core{
        interface IWindow{}
        interface IApplicationCore{}
        class ApplicationCore{}
        IApplicationCore <|.. ApplicationCore
        IWindow <.. IApplicationCore
    }
}
```
- IApplicationCoreインターフェース
    - グラフィックスAPIに応じたウィンドウ作成
    - シーンの登録
    - アクターの登録

### 3. シーン関連

```plantuml
namespace System{
    namespace SceneManagement{
        interface ISceneManager{}
        class SceneManager{}
        class Scene{}
        ISceneManager <.. SceneManager
    }
}
```
- SceneManager
- Scene
- Actor

