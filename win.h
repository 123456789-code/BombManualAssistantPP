#pragma once
#include <windows.h>

// 检查当前是否以管理员权限运行
BOOL IsRunAsAdmin() {
	BOOL isAdmin = FALSE;
	PSID adminGroup = NULL;

	// 创建管理员组的 SID
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	if (AllocateAndInitializeSid(&NtAuthority, 2,
		SECURITY_BUILTIN_DOMAIN_RID,
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&adminGroup)) {

		if (!CheckTokenMembership(NULL, adminGroup, &isAdmin)) {
			isAdmin = FALSE;
		}

		FreeSid(adminGroup);
	}

	return isAdmin;
}

// 请求以管理员权限重新启动程序
BOOL RestartAsAdmin() {
	WCHAR szPath[MAX_PATH];
	if (GetModuleFileName(NULL, szPath, ARRAYSIZE(szPath))) {
		SHELLEXECUTEINFO sei = { sizeof(sei) };

		sei.lpVerb = L"runas";  // 请求提升权限的关键
		sei.lpFile = szPath;
		sei.hwnd = NULL;
		sei.nShow = SW_NORMAL;

		if (ShellExecuteEx(&sei)) {
			return TRUE;
		}
		else {
			DWORD dwError = GetLastError();
			if (dwError == ERROR_CANCELLED) {
				// 用户拒绝了 UAC 提示
				MessageBox(NULL, L"需要管理员权限才能继续操作", L"权限不足", MB_ICONWARNING);
			}
			return FALSE;
		}
	}
	return FALSE;
}