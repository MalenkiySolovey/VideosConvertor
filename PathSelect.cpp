#include "Headers\PathSelect.h"
#include <Windows.h>
#include <shlobj_core.h>

void selectPath(std::string& _NewPath) {
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    BROWSEINFO bi = { 0 };
    bi.lpszTitle = L"Выберите папку";
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != NULL) {
        wchar_t path[MAX_PATH];
        if (SHGetPathFromIDList(pidl, path)) {
            std::wstring wstringptr = path;
            std::string stringptr(wstringptr.begin(), wstringptr.end());
            _NewPath = stringptr;
            _NewPath += '\\';
        }
        CoTaskMemFree(pidl);
    }
    CoUninitialize();

}

_bool selectFile(std::string& _NewPath) {
    TCHAR szFileName[1024];
    const TCHAR* FilterSpec = L"mp4 only\0*.mp4\0";
    const TCHAR* Title = L"Open";
    const TCHAR* myDir = L"C:";
    OPENFILENAME ofn; 
    TCHAR szFileTitle[MAX_PATH] = { '\0' };
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    *szFileName = 0;
    /* fill in non-variant fields of OPENFILENAME struct. */
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = GetFocus(); 
    ofn.lpstrFilter = FilterSpec; 
    ofn.lpstrCustomFilter = NULL; 
    ofn.nMaxCustFilter = 0; 
    ofn.nFilterIndex = 0;
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrInitialDir = myDir; // Initial directory.
    ofn.lpstrFileTitle = szFileTitle;
    ofn.nMaxFileTitle = MAX_PATH;
    ofn.lpstrTitle = Title;
    //ofn.lpstrDefExt = 0; // I've set to null for demonstration
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    if (GetOpenFileName(&ofn) == 1) {
        std::wstring wstringptr = szFileName; 
        std::string stringptr(wstringptr.begin(), wstringptr.end());
        _NewPath = stringptr;
        return 1;
    } else return 0;
}



