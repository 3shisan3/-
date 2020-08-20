#include "stdafx.h"
#include "bw.h"

#include "MainFrm.h"
#include "bwDoc.h"
#include "bwView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBwApp

BEGIN_MESSAGE_MAP(CBwApp, CWinApp)
	//{{AFX_MSG_MAP(CBwApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		//注意 - ClassWizard将在此处添加和删除映射宏。.
		//  不要编辑在这些生成的代码块中看到的内容！
	//}}AFX_MSG_MAP
	// 基于标准文件的文档命令
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBwApp construction

CBwApp::CBwApp()
{
	// 待办事项：在此处添加施工代码，
	// 将所有重要的初始化都放在InitInstance中
}

/////////////////////////////////////////////////////////////////////////////
//唯一的CBwApp对象
 
CBwApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBwApp 初始化

BOOL CBwApp::InitInstance()
{
	AfxEnableControlContainer();

	// 标准初始化
	// 如果您不使用这些功能并希望减小最终可执行文件的大小，则应从以下内容中删除不需要的特定初始化例程。

#ifdef _AFXDLL
	Enable3dControls();			// 在共享DLL中使用MFC时调用此函数
#else
	Enable3dControlsStatic();	// 静态链接到MFC时调用此方法
#endif

	// 更改用于存储我们的设置的注册表项。
	// TODO：您应该将此字符串修改为适当的值
	// 例如您公司或组织的名称。
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // 加载标准INI文件选项（包括MRU）

	// 注册应用程序的文档模板。文档模板充当文档，框架窗口和视图之间的连接。

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CBwDoc),
		RUNTIME_CLASS(CMainFrame),       // 主SDI框架窗口
		RUNTIME_CLASS(CBwView));
	AddDocTemplate(pDocTemplate);

	// 解析命令行以获取标准Shell命令，DDE，文件打开
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// 调度在命令行上指定的命令
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已经初始化，因此请显示并更新它。
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// 用于App About的CAboutDlg对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// 应用程序命令运行对话框
void CBwApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CBwApp 消息处理程序

