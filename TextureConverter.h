#pragma once
#include <string>
#include <Windows.h>
#include "DirectXTex/DirectXTex.h"
class TextureConverter
{
public:

	void ConvertTextureWICToDDS(const std::string& filePath);

private:

	/// <summary>
	/// テクスチャファイル読み込み
	/// </summary>
	/// <param name="filePath"></param>
	void LoadWICTextureFromFile(const std::string& filePath);

	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

private:
	// 画像の情報
	DirectX::TexMetadata metadata_;
	// 画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;

	/// <summary>
	/// フォルダパスとファイル名を分離する
	/// </summary>
	/// <param name="filePath"></param>
	void SeparateFilePath(const std::wstring& filePath);

private:
	// ディレクトリパス
	std::wstring directoryPath_;
	// ファイル名
	std::wstring fileName_;
	// ファイル拡張子
	std::wstring fileExt_;

private:

	/// <summary>
	/// DDSテクスチャとしてファイル書き出し
	/// </summary>
	void SaveDDSTextureToFile();

	HRESULT result_;
};

