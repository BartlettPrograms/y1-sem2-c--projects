#include "cFileInterface.h"

cFileInterface::cFileInterface()
{

}

cFileInterface::~cFileInterface()
{

}

void cFileInterface::LoadFile(sf::RenderTexture* _Texture)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	if (SUCCEEDED(hr))
	{
		// creates the dialog
		IFileOpenDialog* pFileOpen;

		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			hr = pFileOpen->Show(NULL);

			// get the file name from the box
			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					if (SUCCEEDED(hr))
					{
						sf::Texture newTex(pszFilePath);
						sf::Sprite newSprite(newTex);

						_Texture->draw(newSprite);
						_Texture->display();

						CoTaskMemFree(pszFilePath);
					}

					pItem->Release();
				}
			}

			pFileOpen->Release();
		}

		CoUninitialize();
	}
}

void cFileInterface::LoadStamp(sf::Texture* _Texture)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	if (SUCCEEDED(hr))
	{
		// creates the dialog
		IFileOpenDialog* pFileOpen;

		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			hr = pFileOpen->Show(NULL);

			// get the file name from the box
			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					if (SUCCEEDED(hr))
					{
						sf::Texture newTex(pszFilePath);
						_Texture->swap(newTex);

						CoTaskMemFree(pszFilePath);
					}

					pItem->Release();
				}
			}

			pFileOpen->Release();
		}

		CoUninitialize();
	}
}

void cFileInterface::SaveFile(sf::RenderTexture* _Texture)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	if (SUCCEEDED(hr))
	{
		// creates the dialog
		IFileOpenDialog* pFileSave;

		hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
			IID_IFileSaveDialog, reinterpret_cast<void**>(&pFileSave));

		if (SUCCEEDED(hr))
		{
			hr = pFileSave->Show(NULL);

			// get the file name from the box
			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileSave->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					if (SUCCEEDED(hr))
					{
						sf::Texture texture = _Texture->getTexture();
						sf::Image image = texture.copyToImage();

						if (image.saveToFile(std::wstring(pszFilePath)))
						{
							std::cout << "File saved successfully" << std::endl;
						}
						else
						{
							std::cout << "Failed to save file :(" << std::endl;
						}
						CoTaskMemFree(pszFilePath);
					}

					pItem->Release();
				}
			}

			pFileSave->Release();
		}

		CoUninitialize();
	}
}