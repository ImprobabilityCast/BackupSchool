/***************************************************************
 * Name:      BackupSchool3App.h
 * Purpose:   Defines Application Class
 * Author:    ImprobabilityCast
 * Created:   2017-02-12
 * Copyright: ImprobabilityCast
 * License:
 **************************************************************/

#ifndef BACKUPSCHOOL3APP_H
#define BACKUPSCHOOL3APP_H

#include <signal.h>

#include <wx/msgdlg.h>
#include <wx/app.h>

class BackupSchool3App : public wxApp
{

    public:
        virtual bool OnInit();
        int OnExit();
        int OnRun();
};

#endif // BACKUPSCHOOL3APP_H
