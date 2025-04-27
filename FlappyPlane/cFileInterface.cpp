#include "cFileInterface.h"

cFileInterface::cFileInterface()
{

}

cFileInterface::~cFileInterface()
{

}

void cFileInterface::SaveLevelDialog(const cLevelPlatformsList& platformList) {
    // Initialize COM
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM" << std::endl;
        return;
    }

    // Create Save File Dialog
    IFileSaveDialog* pFileSave = nullptr;
    hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
        IID_IFileSaveDialog, (void**)&pFileSave);

    if (SUCCEEDED(hr)) {
        // Set file types
        COMDLG_FILTERSPEC fileTypes[] = {
            { L"JSON files", L"*.json" },
            { L"All files", L"*.*" }
        };
        pFileSave->SetFileTypes(2, fileTypes);
        pFileSave->SetDefaultExtension(L"json");

        // Show dialog
        hr = pFileSave->Show(NULL);
        if (SUCCEEDED(hr)) {
            IShellItem* pItem;
            hr = pFileSave->GetResult(&pItem);
            if (SUCCEEDED(hr)) {
                PWSTR pszFilePath;
                hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
                if (SUCCEEDED(hr)) {
                    // Create JSON document
                    rapidjson::Document doc;
                    doc.SetObject();
                    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

                    // Create platforms array
                    rapidjson::Value platformsArray(rapidjson::kArrayType);

                    // Add each platform to json list
                    for (auto* platform : platformList.mPlatformList) {
                        rapidjson::Value platformObj(rapidjson::kObjectType);
                        sf::FloatRect bounds = platform->GetColliderCopy().GetBounds();

                        platformObj.AddMember("x", bounds.position.x, allocator);
                        platformObj.AddMember("y", bounds.position.y, allocator);
                        platformObj.AddMember("width", bounds.size.x, allocator);
                        platformObj.AddMember("height", bounds.size.y, allocator);

                        platformsArray.PushBack(platformObj, allocator);
                    }

                    doc.AddMember("platforms", platformsArray, allocator);

                    // Write to JSON string
                    rapidjson::StringBuffer buffer;
                    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
                    doc.Accept(writer);

                    // Write to file
                    std::ofstream outFile(pszFilePath);
                    if (outFile.is_open()) {
                        outFile << buffer.GetString();
                        outFile.close();
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

void cFileInterface::LoadLevelDialog(cLevelPlatformsList& platformList)
{
	//HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	//if (SUCCEEDED(hr))
	//{
	//	// creates the dialog
	//	IFileOpenDialog* pFileOpen;

	//	hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
	//		IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

	//	if (SUCCEEDED(hr))
	//	{
	//		hr = pFileOpen->Show(NULL);

	//		// get the file name from the box
	//		if (SUCCEEDED(hr))
	//		{
	//			IShellItem* pItem;
	//			hr = pFileOpen->GetResult(&pItem);
	//			if (SUCCEEDED(hr))
	//			{
	//				PWSTR pszFilePath;
	//				hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
	//				if (SUCCEEDED(hr))
	//				{
	//					sf::Texture newTex(pszFilePath);
	//					sf::Sprite newSprite(newTex);

	//					/*_Texture->draw(newSprite);
	//					_Texture->display();*/

	//					CoTaskMemFree(pszFilePath);
	//				}

	//				pItem->Release();
	//			}
	//		}

	//		pFileOpen->Release();
	//	}

	//	CoUninitialize();
	//}
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