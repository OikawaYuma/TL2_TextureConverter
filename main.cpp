#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"

enum Argument {
	kAppricationpath, // アプリケーションのパス
	kFilePath,		  // 渡されたファイルのパス
	NumArgument
};

int main(int argc, char* argv[]) {

	// argcの数だけ繰り返す
	for (int i = 0; i < argc; i++) {
		// 文字列argvのi番を表示
		printf(argv[i]);
		// 改行
		printf("\n");
	}
	

	assert(argc >= NumArgument);

	// COM ライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	// テクスチャ変換
	TextureConverter converter;

	// テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);
	// COM ライブラリの終了
	CoUninitialize();
	system("pause");
	return 0;
}