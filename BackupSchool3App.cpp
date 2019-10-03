/***************************************************************
 * Name:      BackupSchool3App.cpp
 * Purpose:   Code for Application Class
 * Author:    ImprobabilityCast
 * Created:   2017-02-12
 * Copyright: ImprobabilityCast
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "BackupSchool3App.h"

//(*AppHeaders
#include "BackupSchool3Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(BackupSchool3App);

bool FrameExists=false;
BackupSchool3Frame* Frame;

void errorSignal(int signum){
    switch(signum){
case SIGABRT:
    wxMessageBox(wxT("SIGABRT: This program was abnormally terminated, or it received a call to abort."),
                               wxT("Error - BackupSchool"),wxICON_ERROR);
    break;
case SIGFPE:
    wxMessageBox(wxT("SIGFPE: Arithmetic error, such as a divide by zero, or an operation resulting in overflow."),
                               wxT("Error - BackupSchool"),wxICON_ERROR);
    break;
case SIGILL:
    wxMessageBox(wxT("SIGILL: Illegal instruction detected"),
                               wxT("Error - BackupSchool"),wxICON_ERROR);
    break;
case SIGINT:
    wxMessageBox(wxT("SIGINT: Interactive attention signal received"),
                               wxT("Error - BackupSchool"),wxICON_ERROR);
    break;
case SIGSEGV:
    wxMessageBox(wxT("SIGSEGV: Invalid access to storage.  Segmentation fault."),
                               wxT("Error - BackupSchool"),wxICON_ERROR);
    break;
default:
    wxMessageBox(wxT("Unkown signal received"),
                               wxT("Error - BackupSchool"),wxICON_ERROR);
    }
    if(FrameExists)
        Frame->ClearPtrs();
    exit(signum);
}

bool BackupSchool3App::OnInit()
{
    // call default behaviour (mandatory)
    if (!wxApp::OnInit())
        return false;

    //signal handling
    signal(SIGABRT, errorSignal); //SIGABRT     Abnormal termination of the program, such as a call to abort
    signal(SIGFPE, errorSignal);  //SIGFPE      An erroneous arithmetic operation, such as a divide by zero
                                  //                or an operation resulting in overflow.
    signal(SIGILL, errorSignal);  //SIGILL      Detection of an illegal instruction
    signal(SIGINT, errorSignal);  //SIGINT      Receipt of an interactive attention signal.
    signal(SIGSEGV, errorSignal); //SIGSEGV 	An invalid access to storage.  A segmentation fault
    signal(SIGTERM, errorSignal); //SIGTERM 	A termination request sent to the program.

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	BackupSchool3Frame* Frame = new BackupSchool3Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
}

int BackupSchool3App::OnExit()
{
    //clean up
    return 0;
}

int BackupSchool3App::OnRun()
{
    return wxApp::OnRun();
}
