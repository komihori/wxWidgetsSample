#include "../include/MyApp.hpp"
#include "../include/MyFrame.hpp"

// アプリケーションの初期化処理。
// 実質的な main 関数の代わりと思って良い。
// true を返した場合はメインループに突入し、 false を返した場合はそのまま終了する。
bool MyApp::OnInit() {
    // コマンドライン引数を処理する。
    if(!wxApp::OnInit())
        return false;

    MyFrame* frame = new MyFrame;
    frame->Show();

    return true;
}