/***************************************************************
 * Name:      BackupSchool3Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    ImprobabilityCast
 * Created:   2017-02-12
 * Copyright: ImprobabilityCast
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "BackupSchool3Main.h"
#include <wx/msgdlg.h>

// v2.2.x uses c++11 & WxWidgets 3.0.x

#define MAJOR_VERSION      2
#define MINOR_VERSION      2
#define RELEASE_NUMBER     2
#define BUILD_NUMBER       14
#define TOSTR2(x) #x
#define TOSTR(x) TOSTR2(x)
#define VERSION_STRING     wxT( "BackupSchool.exe v" TOSTR(MAJOR_VERSION) "." \
                                TOSTR(MINOR_VERSION) "." \
                                TOSTR(RELEASE_NUMBER) "." \
                                TOSTR(BUILD_NUMBER) )

#include <wx/settings.h> //for wxSYS_COLOUR_WINDOWTEXT
                // to change txt color in textbox back to default
//(*InternalHeaders(BackupSchool3Frame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


//(*IdInit(BackupSchool3Frame)
const long BackupSchool3Frame::ID_BUTTON1 = wxNewId();
const long BackupSchool3Frame::ID_BUTTON2 = wxNewId();
const long BackupSchool3Frame::ID_SCROLLEDWINDOW1 = wxNewId();
const long BackupSchool3Frame::ID_TEXTCTRL1 = wxNewId();
const long BackupSchool3Frame::ID_CHECKBOX1 = wxNewId();
const long BackupSchool3Frame::ID_PANEL1 = wxNewId();
const long BackupSchool3Frame::idMenuSave = wxNewId();
const long BackupSchool3Frame::idMenuQuit = wxNewId();
const long BackupSchool3Frame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(BackupSchool3Frame,wxFrame)
    //(*EventTable(BackupSchool3Frame)
    //*)
END_EVENT_TABLE()

/*BackupSchool3Frame::BackupSchool3Frame(wxWindow* parent,wxWindowID id, int pig)
{
    //(*Initialize(BackupSchool3Frame)
    wxMenuItem* MenuItem2;
    wxGridBagSizer* GridBagSizer1;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxMenuItem* MenuItem3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("BackupSchool"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("main.ico"))));
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    GridBagSizer1 = new wxGridBagSizer(0, 50);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Backup"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetDefault();
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    GridBagSizer1->Add(BoxSizer2, wxGBPosition(3, 0), wxGBSpan(1, 4), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrolledWindow1 = new wxScrolledWindow(Panel1, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxSize(268,64), wxSUNKEN_BORDER|wxVSCROLL|wxHSCROLL|wxFULL_REPAINT_ON_RESIZE, _T("ID_SCROLLEDWINDOW1"));
    ScrolledWindow1->SetMinSize(wxSize(400,300));
    GridBagSizer1->Add(ScrolledWindow1, wxGBPosition(2, 0), wxGBSpan(1, 4), wxALL|wxEXPAND, 5);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Text!"), wxDefaultPosition, wxSize(308,66), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    GridBagSizer1->Add(TextCtrl1, wxGBPosition(0, 0), wxGBSpan(1, 4), wxALL|wxEXPAND, 5);
    CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Toggle All"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    GridBagSizer1->Add(CheckBox1, wxGBPosition(1, 0), wxDefaultSpan, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    Panel1->SetSizer(GridBagSizer1);
    GridBagSizer1->Fit(Panel1);
    GridBagSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu1, idMenuSave, _("Save Log...\tCtrl-S"), _("Save the output log"), wxITEM_NORMAL);
    Menu1->Append(MenuItem2);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem3);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BackupSchool3Frame::OnBackupClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BackupSchool3Frame::OnCancelClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&BackupSchool3Frame::OnToggleAll);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BackupSchool3Frame::OnSave);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BackupSchool3Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BackupSchool3Frame::OnAbout);
    //*)
}*///*/

void playSnd() {
    PlaySound(TEXT("write_success.wav"), NULL, SND_FILENAME);
}
class Configure {
public:
    bool good;

    Configure() {
        good=true;
    }

    std::string GetConfigAttrib(std::ifstream& config, const char* str) {
        std::string out ("#");
        while (out[0] == '#') {
            tryagain:
            std::getline(config, out);
            if (config.eof()) {
                good=false;
                return out;
            }
        }
        //see if read attrib matches attrib specified in str
        size_t index = out.find(' ',0);
        if (index == std::string::npos) {
            good=false;
            return out;
        }
        if ( 0 != strcmp(str, out.substr(0, index).c_str()) )
            goto tryagain;

        out.erase(out.size()-1);
        if(out[out.size()-1] != '\\')
            out.push_back('\\');
        out = out.substr(index+1);
        return out;
    }
};

//dynamic memory clearing
void BackupSchool3Frame::ClearPtrs(){
    if (writable != nullptr) {
        delete[] writable;
    }
    if (CheckBoxArr != nullptr){
        for(int i=0; i<fileCnt; i++)
            delete CheckBoxArr[i];
        delete[] CheckBoxArr;
    }
    if (args != nullptr){
        delete[] args;
    }
    if (ID_CH_ARR != nullptr){
        delete[] ID_CH_ARR;
    }
}

///@brief Displays the specified error message and exits the program
void BackupSchool3Frame::ErrorMessage(const char * message, long style){
    ClearPtrs();
    wxMessageBox(wxString::FromUTF8(message),
                    wxT("Error"),style);
    exit(-1);
}

void BackupSchool3Frame::ErrorMessage(std::string message, long style){
    ErrorMessage(message.c_str());
}

void BackupSchool3Frame::LogMessage(const char* message){
    wxString m = wxString::FromUTF8(message);
    m += wxT("\n");
    TextCtrl1->AppendText(m);
}

///@brief Checks if any write flags are set.  If so, it
/// prints an error message and exits the program.
template <typename T>
bool BackupSchool3Frame::TestFlags(T * file) {
    bool result = false;
    if(!file->good()){
        LogMessage("Failed.  File read/write Error");
        file->close();
        result = true;
    }
    return result;
}

void BackupSchool3Frame::Conf(){

    targetDir = "#";
    std::string rootDir ("#");
    std::string confFilePath = "BackupSchool.conf";

    //configure BackupSchool
    std::ifstream config (confFilePath.c_str(), std::ios::binary);
    if (config.is_open()) {
        Configure conf;
        targetDir = conf.GetConfigAttrib(config, "TargetDirectory");
        rootDir = conf.GetConfigAttrib(config, "RootDirectory");
        if(!conf.good)
            ErrorMessage("BackupSchool could not configure");
        if(TestFlags(&config))
            exit(-1);
        config.close();
    } else {
        ErrorMessage("This program's .conf file '" + confFilePath
                     + "' could not be found");
    }

    //std::vector<char*> args;
    //seach root dir for files that were modified today
    std::string names;
    fileCnt = 0;
    std::string search_path = rootDir + "*";
    WIN32_FIND_DATAA fd;
    HANDLE hFind = FindFirstFileA(search_path.c_str(), &fd);

    if(hFind != INVALID_HANDLE_VALUE) {
        HANDLE hand;
        FILETIME lastWriteTime, localWriteTime;
        SYSTEMTIME systemTime, currentTime;
        GetLocalTime(&currentTime);
        std::string fileName;
        do{ //if handle is not pointing to a directory
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ){
            #ifdef DEBUG
                std::cout << fd.cFileName << std::endl;
            #endif
                fileName.assign(rootDir).append(fd.cFileName);
                hand = CreateFileA(fileName.c_str(), GENERIC_READ,
                            FILE_SHARE_READ, NULL,OPEN_EXISTING, 0, NULL);
                if(hand == INVALID_HANDLE_VALUE)
                    ErrorMessage("File could not be opened.  Invalid handle value.");
/*  File time   */  if(!GetFileTime(hand, NULL, NULL, &lastWriteTime))
/*  conversions */      ErrorMessage("Couldn't get file time");
                if(!FileTimeToLocalFileTime(&lastWriteTime, &localWriteTime))
                    ErrorMessage("Couldn't convert to local time");
                if(!FileTimeToSystemTime(&localWriteTime, &systemTime))
                    ErrorMessage("Could not convert file time to system time");
                if( (systemTime.wYear == currentTime.wYear) &&
                    (systemTime.wMonth == currentTime.wMonth) &&
                    (systemTime.wDay == currentTime.wDay) )
                    {
      //if file was last modified today, add it to list
      // of files to backup
                    names += rootDir;
                    names += fd.cFileName;
                    names += ";";
                    fileCnt++;
                }
                CloseHandle(hand);
            }
        }while(FindNextFileA(hFind, &fd));
        FindClose(hFind);
    }else{
        ErrorMessage("No files found in the configured directory");
    }

    if (fileCnt == 0) {
        ErrorMessage("No files need to be backed up as far as I can tell.", wxICON_INFORMATION);
    }

    writable = new (std::nothrow) char[names.size()+1];
    CheckBoxArr = new (std::nothrow) wxCheckBox*[fileCnt];
    args = new (std::nothrow) char*[fileCnt];
    if (writable == nullptr || CheckBoxArr == nullptr
            || args == nullptr) {
        ErrorMessage("Memory could not be allocated.");
    }

    try{
        //seperate names string into seperate c-strings
        std::copy(names.begin(), names.end(), writable);
        writable[names.size()] = '\0';
        args[0] = strtok(writable, ";");
        for(int i=1; i<fileCnt; i++)
            args[i] = strtok(NULL, ";");
    }catch(...){
        ErrorMessage("Exception thrown. Very helpful message, isn't it.");
    }
}

BackupSchool3Frame::BackupSchool3Frame(wxWindow* parent, wxWindowID id)
{
    Conf();

    //std::vector<long> ID_CH_ARR2;
    ID_CH_ARR = new (std::nothrow) long[fileCnt];
    if (ID_CH_ARR == nullptr) {
        ErrorMessage("Memory could not be allocated.");
    }

    for(int i=0; i<fileCnt; i++)
        ID_CH_ARR[i] = wxNewId();
//ASCII 48-57(dec) 30-39(hex) = 0-9 (char)

    const char* idStrArr[] = {
"ID_CHECKBOX2","ID_CHECKBOX3","ID_CHECKBOX4",
"ID_CHECKBOX5","ID_CHECKBOX6","ID_CHECKBOX7","ID_CHECKBOX8",
"ID_CHECKBOX9","ID_CHECKBOX10","ID_CHECKBOX11","ID_CHECKBOX12",
"ID_CHECKBOX13","ID_CHECKBOX14","ID_CHECKBOX15","ID_CHECKBOX16",
"ID_CHECKBOX17","ID_CHECKBOX18","ID_CHECKBOX19","ID_CHECKBOX20",
"ID_CHECKBOX21","ID_CHECKBOX22","ID_CHECKBOX23","ID_CHECKBOX24",
"ID_CHECKBOX25","ID_CHECKBOX26","ID_CHECKBOX27","ID_CHECKBOX28",
"ID_CHECKBOX29","ID_CHECKBOX30","ID_CHECKBOX31"
    };
    wxMenuItem* MenuItem2;
    wxGridBagSizer* GridBagSizer1;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;


    Create(parent, wxID_ANY, _("BackupSchool"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("main.ico"))));
    	SetIcon(FrameIcon);
    }

    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    GridBagSizer1 = new wxGridBagSizer(0, 50);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Backup"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetDefault();
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    GridBagSizer1->Add(BoxSizer2, wxGBPosition(3, 0), wxGBSpan(1, 4), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrolledWindow1 = new wxScrolledWindow(Panel1, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxSize(268,64), wxSUNKEN_BORDER|wxVSCROLL|wxHSCROLL|wxFULL_REPAINT_ON_RESIZE, _T("ID_SCROLLEDWINDOW1"));
    ScrolledWindow1->SetMinSize(wxSize(400,300));
	for(int i=0; i<fileCnt; i++){
        CheckBoxArr[i] = new wxCheckBox(ScrolledWindow1, ID_CH_ARR[i], wxString::FromUTF8(args[i]), wxPoint(5,20*i+5), wxDefaultSize, 0, wxDefaultValidator, wxString::FromUTF8(idStrArr[i]));
        CheckBoxArr[i]->SetValue(true);
    }

	//had to add these to make the scrollbars work
    ScrolledWindow1->SetScrollbars(2,2,50,50);
    ScrolledWindow1->SetVirtualSize(0, fileCnt*20+5);

    GridBagSizer1->Add(ScrolledWindow1, wxGBPosition(2, 0), wxGBSpan(1, 4), wxALL|wxEXPAND, 5);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Do you want to backup these files\?\n"), wxDefaultPosition, wxSize(308,80), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    GridBagSizer1->Add(TextCtrl1, wxGBPosition(0, 0), wxGBSpan(1, 4), wxALL|wxEXPAND, 5);
    CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Toggle All"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    GridBagSizer1->Add(CheckBox1, wxGBPosition(1, 0), wxDefaultSpan, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    Panel1->SetSizer(GridBagSizer1);
    GridBagSizer1->Fit(Panel1);
    GridBagSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu1, idMenuSave, _("Save Log...\tCtrl-S"), _("Save the output log"), wxITEM_NORMAL);
    Menu1->Append(MenuItem2);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BackupSchool3Frame::OnBackupClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BackupSchool3Frame::OnCancelClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&BackupSchool3Frame::OnToggleAll);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BackupSchool3Frame::OnSave);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BackupSchool3Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BackupSchool3Frame::OnAbout);

}

BackupSchool3Frame::~BackupSchool3Frame()
{
    //(*Destroy(BackupSchool3Frame)
    //*)
    ClearPtrs();
}

void BackupSchool3Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void BackupSchool3Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = VERSION_STRING;
    msg += wxT("\n") + wxbuildinfo(long_f);
    wxMessageBox(msg, _("BackupSchool"));
}

void BackupSchool3Frame::OnCancelClick(wxCommandEvent& event)
{
    Close();
}

void timeStr(char tmBuf[13]){
    //get current time
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    strftime(tmBuf, 13, "(%Y-%m-%d)", timeinfo);
}

void BackupSchool3Frame::OnBackupClick(wxCommandEvent& event)
{
    //for counting how many files failed
    int fails=0;
    //for counting how many files were skipped
    int skip=0;
    try{
        //get current time
        char tmBuf[13];
        timeStr(tmBuf);
        //loop for copying files.  Runs once for each file
        for(int i=0; i<fileCnt; i++){
            //only copy checked files
            if(!CheckBoxArr[i]->GetValue()){
                skip++;
                wxString t = wxT("Skipping file ");
                t += wxString::Format(wxT("%i"), i+1);
                t += wxT(" :\n");
                t += wxString::FromUTF8(args[i]);
                t += wxT("\n");
                TextCtrl1->AppendText(t);
                continue;
            }
            const char* input = args[i];
            //update status
            wxString txt = wxT("Copying file ");
            txt += wxString::Format(wxT("%i"), i+1);
            txt += wxT(" of ");
            txt += wxString::Format(wxT("%i"), fileCnt);
            txt += wxT(":\n");
            txt += wxString::FromUTF8(input);
            txt += wxT("\n");
            TextCtrl1->AppendText(txt);

            std::string output = targetDir;
            std::ifstream ifile (input, std::ios::binary);
            if(ifile.is_open()){
                /*std::vector<char> buffer(
                    (std::istreambuf_iterator<char>(ifile)),
                    (std::istreambuf_iterator<char>())
                                    );
                if(TestFlags(&ifile)){
                    fails++;
                    continue;
                }*/
                const char* filename = strrchr(input, '\\');
                if(filename == 0)
                    filename = strrchr(input, '/');
                filename++;
                output.append(filename);
                //append today's date to filename
                size_t index = output.find_last_of('.', output.size()-1);
                if(index != std::string::npos)
                    output.insert(index, tmBuf);
                else
                    output.append(tmBuf);

                std::ifstream temp(output.c_str());
                if(temp.is_open()){
                    LogMessage("It seems you've already backed that one up today.");
                    fails++;
                    continue;
                }

                std::ofstream ofile (output.c_str(), std::ios::binary);
                if(ofile.is_open()){
                    std::copy( std::istreambuf_iterator<char>(ifile),
                               std::istreambuf_iterator<char>(),
                               std::ostreambuf_iterator<char>(ofile) );
                    if(TestFlags(&ofile)){
                        LogMessage("Error copying file.");
                        fails++;
                        continue;
                    }
                    LogMessage("Successful.");
                }
                else{
                    LogMessage("Failed.  File could not be copied.  "
                                "Did you change my .conf file?\n"
                                "Um...  You know you need to insert the proper flashdrive,\n"
                                "right?");
                    fails++;
                    continue;
                }
            }
            else{
                wxMessageBox(wxT("File could not be opened:  "
                            "No such file or directory\n"
                            "What on earth are you trying to do?!"),
                            wxT("Error"), wxICON_ERROR);
                return;
            }
        }
    }catch(...){
        LogMessage("Exception thrown");
        return;
    }
    if(fails > 0){
        TextCtrl1->SetForegroundColour(wxColour(0x0000ffUL));
        wxString failStr = wxT("ERROR: ") +
            wxString::Format(wxT("%i"), fails) +
            wxT(" of ") + wxString::Format(wxT("%i"), fileCnt-skip) +
            wxT(" files were not copied succesfully.\nSee log.\n");
        TextCtrl1->AppendText(failStr);
    }
    else{
        if(fileCnt != skip){
            TextCtrl1->SetForegroundColour(wxColour(0x00dd00UL));
            TextCtrl1->AppendText(wxString::Format(wxT("%i"), fileCnt-skip));
            LogMessage(" Files were copied successfully.");
            playSnd();
        }else{
            TextCtrl1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
            LogMessage("Ok.  Nothing to for me to do, you silly!");
        }
    }
}

void BackupSchool3Frame::OnSave(wxCommandEvent& event)
{
    wxString filename = wxT("BackupSchool");
    char tmBuf[13];
    timeStr(tmBuf);
    filename += wxString::FromUTF8(tmBuf);
    filename += wxT(".log");
    wxFileDialog* ofd = new wxFileDialog(this,
                                        wxT("Save As"),
                                        wxEmptyString,
                                        filename,
                                        wxT("Text Files (*.txt)(*.log)|*.txt;*.log|All Files (*.*)|*.*"),
                                        wxFD_SAVE);
    if(ofd->ShowModal() == wxID_OK)
        TextCtrl1->SaveFile(ofd->GetPath());
    delete ofd;
}

void BackupSchool3Frame::OnToggleAll(wxCommandEvent& event)
{
    bool val = CheckBox1->GetValue();
    for(int i=0; i<fileCnt; i++)
        CheckBoxArr[i]->SetValue(val);
}
