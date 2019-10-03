/***************************************************************
 * Name:      BackupSchool3Main.h
 * Purpose:   Defines Application Frame
 * Author:    ImprobabilityCast
 * Created:   2017-02-12
 * Copyright: ImprobabilityCast
 * License:
 **************************************************************/

#ifndef BACKUPSCHOOL3MAIN_H
#define BACKUPSCHOOL3MAIN_H

//(*Headers(BackupSchool3Frame)
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class BackupSchool3Frame: public wxFrame
{
    public:

        //BackupSchool3Frame(wxWindow* parent,wxWindowID id, int pig);
        BackupSchool3Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~BackupSchool3Frame();
        void ClearPtrs();

    private:
        void LogMessage(const char* message);
        void ErrorMessage(const char* message, long style = wxICON_ERROR);
        void ErrorMessage(std::string message, long style = wxICON_ERROR);
        std::string targetDir;
        template <typename T>
        bool TestFlags(T * file);
       // bool TestFlags(std::ofstream * file);
        //bool TestFlags(std::ifstream * file);
        void Conf();
        //(*Handlers(BackupSchool3Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnCancelClick(wxCommandEvent& event);
        void OnBackupClick(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnToggleAll(wxCommandEvent& event);
        //*)

        //(*Identifiers(BackupSchool3Frame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_TEXTCTRL1;
        static const long ID_CHECKBOX1;
        static const long ID_PANEL1;
        static const long idMenuSave;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)

        int fileCnt;

        //dynamic ptrs
        char* writable;
        long* ID_CH_ARR;
        wxCheckBox** CheckBoxArr;
        char** args;

        //(*Declarations(BackupSchool3Frame)
        wxScrolledWindow* ScrolledWindow1;
        wxButton* Button1;
        wxPanel* Panel1;
        wxButton* Button2;
        wxCheckBox* CheckBox1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BACKUPSCHOOL3MAIN_H
