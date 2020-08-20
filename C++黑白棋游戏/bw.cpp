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
		//ע�� - ClassWizard���ڴ˴���Ӻ�ɾ��ӳ��ꡣ.
		//  ��Ҫ�༭����Щ���ɵĴ�����п��������ݣ�
	//}}AFX_MSG_MAP
	// ���ڱ�׼�ļ����ĵ�����
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBwApp construction

CBwApp::CBwApp()
{
	// ��������ڴ˴����ʩ�����룬
	// ��������Ҫ�ĳ�ʼ��������InitInstance��
}

/////////////////////////////////////////////////////////////////////////////
//Ψһ��CBwApp����
 
CBwApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBwApp ��ʼ��

BOOL CBwApp::InitInstance()
{
	AfxEnableControlContainer();

	// ��׼��ʼ��
	// �������ʹ����Щ���ܲ�ϣ����С���տ�ִ���ļ��Ĵ�С����Ӧ������������ɾ������Ҫ���ض���ʼ�����̡�

#ifdef _AFXDLL
	Enable3dControls();			// �ڹ���DLL��ʹ��MFCʱ���ô˺���
#else
	Enable3dControlsStatic();	// ��̬���ӵ�MFCʱ���ô˷���
#endif

	// �������ڴ洢���ǵ����õ�ע����
	// TODO����Ӧ�ý����ַ����޸�Ϊ�ʵ���ֵ
	// ��������˾����֯�����ơ�
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // ���ر�׼INI�ļ�ѡ�����MRU��

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��䵱�ĵ�����ܴ��ں���ͼ֮������ӡ�

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CBwDoc),
		RUNTIME_CLASS(CMainFrame),       // ��SDI��ܴ���
		RUNTIME_CLASS(CBwView));
	AddDocTemplate(pDocTemplate);

	// �����������Ի�ȡ��׼Shell���DDE���ļ���
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// ��������������ָ��������
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������Ѿ���ʼ�����������ʾ����������
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// ����App About��CAboutDlg�Ի���

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

// Ӧ�ó����������жԻ���
void CBwApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CBwApp ��Ϣ�������

