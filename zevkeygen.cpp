#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

void activate(const char* key) {
    if (!key || strlen(key) == 0) {
        printf("Error: No key provided.\n");
        return;
    }
    std::string ipkcommand = "slmgr /ipk ";
    ipkcommand += key;

    int keyactivation = system(ipkcommand.c_str());
    int serveradd = system("slmgr /skms kms.digiboy.ir");
    int activation = system("slmgr /ato");

    if (keyactivation != 0) {
        cout << "Error: Failed to install product key. Please check the key and try again." << endl;
    }
    else {
        cout << "Key installed succesfully!" << endl;
    }
    if (serveradd != 0) {
        cout << "Error: Failed to set KMS server. Please check your network and try again." << endl;
    }
    else {
        cout << "KMS server set succesfully!" << endl;
    }
    if (activation != 0) {
        cout << "Error: Activation failed. Please check the previous steps and try again." << endl;
    }
    else {
        cout << "Succesfully activated! Product is geniue now!" << endl;
    }
}

int main() {
    // Activation keys map
    unordered_map<string, string> windowsKeys = {
        {"Windows 10/11 Pro", "W269N-WFGWX-YVC9B-4J6C9-T83GX"},
        {"Windows 10/11 Pro N", "MH37W-N47XK-V7XM9-C7227-GCQG9"},
        {"Windows 10/11 Pro for Workstations", "NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J"},
        {"Windows 10/11 Pro for Workstations N", "9FNHH-K3HBT-3W4TD-6383H-6XYWF"},
        {"Windows 10/11 Pro Education", "6TP4R-GNPTD-KYYHQ-7B7DP-J447Y"},
        {"Windows 10/11 Pro Education N", "YVWGF-BXNMC-HTQYQ-CPQ99-66QFC"},
        {"Windows 10/11 Education", "NW6C2-QMPVW-D7KKK-3GKT6-VCFB2"},
        {"Windows 10/11 Education N", "2WH4N-8QGBV-H22JP-CT43Q-MDWWJ"},
        {"Windows 10/11 Enterprise", "NPPR9-FWDCX-D2C8J-H872K-2YT43"},
        {"Windows 10/11 Enterprise N", "DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4"},
        {"Windows 10/11 Enterprise G", "YYVX9-NTFWV-6MDM3-9PT4T-4M68B"},
        {"Windows 10/11 Enterprise G N", "44RPN-FTY23-9VTTB-MP9BX-T84FV"},
        {"Windows 10 Enterprise LTSC 2019/2021", "M7XTQ-FN8P6-TTKYV-9D4CC-J462D"},
        {"Windows 10 Enterprise N LTSC 2021/2019", "92NFX-8DJQP-P6BBQ-THF9C-7CG2H"},
        {"Windows 10 Enterprise LTSB 2016", "DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ"},
        {"Windows 10 Enterprise N LTSB 2016", "QFFDN-GRT3P-VKWWX-X7T3R-8B639"},
        {"Windows 10 Enterprise 2015 LTSB", "WNMTR-4C88C-JK8YV-HQ7T2-76DF9"},
        {"Windows 10 Enterprise 2015 LTSB N", "2F77B-TNFGY-69QQF-B8YKP-D69TJ"},
        {"Windows 8.1 Pro", "GCRJD-8NW9H-F2CDX-CCM8D-9D6T9"},
        {"Windows 8.1 Pro N", "HMCNV-VVBFX-7HMBH-CTY9B-B4FXY"},
        {"Windows 8.1 Enterprise", "MHF9N-XY6XB-WVXMC-BTDCT-MKKG7"},
        {"Windows 8.1 Enterprise N", "TT4HM-HN7YT-62K67-RGRQJ-JFFXW"},
        {"Windows 8 Pro", "NG4HW-VH26C-733KW-K6F98-J8CK4"},
        {"Windows 8 Pro N", "XCVCF-2NXM9-723PB-MHCB7-2RYQQ"},
        {"Windows 8 Enterprise", "JMNMF-RHW7P-DMY6X-RF3DR-X2BQT"},
        {"Windows 8 Enterprise N", "TT4HM-HN7YT-62K67-RGRQJ-JFFXW"},
        {"Windows 7 Professional", "FJ82H-XT6CR-J8D7P-XQJJ2-GPDD4"},
        {"Windows 7 Professional N", "MRPKT-YTG23-K7D7T-X2JMM-QY7MG"},
        {"Windows 7 Professional E", "W82YF-2Q76Y-63HXB-FGJG9-GF7QX"},
        {"Windows 7 Enterprise", "33PXH-7Y6KF-2VJC9-XBBR8-HVTHH"},
        {"Windows 7 Enterprise N", "YDRBP-3D83W-TY26F-D46B2-XCKRJ"},
        {"Windows 7 Enterprise E", "C29WB-22CC8-VJ326-GHFJW-H9DH4"},
        {"Windows Vista Business", "YFKBB-PQJJV-G996G-VWGXY-2V3X8"},
        {"Windows Vista Business N", "HMBQG-8H2RH-C77VX-27R82-VMQBT"},
        {"Windows Vista Enterprise", "VKK3X-68KWM-X2YGT-QR4M6-4BWMV"},
        {"Windows Vista Enterprise N", "VTC42-BM838-43QHV-84HX6-XJXKV"}
    };
    // Windows versions map
    map<int, string> windowsVersions;
    windowsVersions[1] = "Windows 10/11 Pro";
    windowsVersions[2] = "Windows 10/11 Pro N";
    windowsVersions[3] = "Windows 10/11 Pro for Workstations";
    windowsVersions[4] = "Windows 10/11 Pro for Workstations N";
    windowsVersions[5] = "Windows 10/11 Pro Education";
    windowsVersions[6] = "Windows 10/11 Pro Education N";
    windowsVersions[7] = "Windows 10/11 Education";
    windowsVersions[8] = "Windows 10/11 Education N";
    windowsVersions[9] = "Windows 10/11 Enterprise";
    windowsVersions[10] = "Windows 10/11 Enterprise N";
    windowsVersions[11] = "Windows 10/11 Enterprise G";
    windowsVersions[12] = "Windows 10/11 Enterprise G N";

    windowsVersions[13] = "Windows 10 Enterprise LTSC 2019/2021";
    windowsVersions[14] = "Windows 10 Enterprise N LTSC 2021/2019";
    windowsVersions[15] = "Windows 10 Enterprise LTSB 2016";
    windowsVersions[16] = "Windows 10 Enterprise N LTSB 2016";
    windowsVersions[17] = "Windows 10 Enterprise 2015 LTSB";
    windowsVersions[18] = "Windows 10 Enterprise 2015 LTSB N";
    windowsVersions[19] = "Windows 8.1 Pro";
    windowsVersions[20] = "Windows 8.1 Pro N";
    windowsVersions[21] = "Windows 8.1 Enterprise";
    windowsVersions[22] = "Windows 8.1 Enterprise N";
    windowsVersions[23] = "Windows 8 Pro";
    windowsVersions[24] = "Windows 8 Pro N";
    windowsVersions[25] = "Windows 8 Enterprise";
    windowsVersions[26] = "Windows 8 Enterprise N";
    windowsVersions[27] = "Windows 7 Professional";
    windowsVersions[28] = "Windows 7 Professional N";
    windowsVersions[29] = "Windows 7 Professional E";
    windowsVersions[30] = "Windows 7 Enterprise";
    windowsVersions[31] = "Windows 7 Enterprise N";
    windowsVersions[32] = "Windows 7 Enterprise E";
    windowsVersions[33] = "Windows Vista Business";
    windowsVersions[34] = "Windows Vista Business N";
    windowsVersions[35] = "Windows Vista Enterprise";
    windowsVersions[36] = "Windows Vista Enterprise N";
    // Main menu
    int selection;
                                 
    cout << " _________   _| | _____ _   _  __ _  ___ _ __  " << endl;
    cout << "|_  / _ \\ \\ / / |/ / _ \\ | | |/ _` |/ _ \\ '_ \\ " << endl;
    cout << " / /  __/\\ V /|   <  __/ |_| | (_| |  __/ | | |" << endl;
    cout << "/___\\___| \\_/ |_|\\_\\___|\\__, |\\__, |\\___|_| |_|" << endl;
    cout << "                        |___/ |___/            " << endl;
    cout << "This tool will help you to activate Windows. Please select options:" << endl;
    cout << "1. Full activation" << endl;
    cout << "2. Custom key activation" << endl;
    cout << "3. Help" << endl;
    cin >> selection;
    if (selection == 1){
        int winver;
        cout << "Please select your windows edition: " << endl;
        for (const auto& entry : windowsVersions) {
            cout << entry.first << ". " << entry.second << endl;
        }
        cin >> winver;
        auto it = windowsVersions.find(winver);
        if (it != windowsVersions.end()) {
            // Works if user enters valid choice.
            string strkey = windowsKeys[windowsVersions[winver]];
            if (!strkey.empty()) {
                activate(strkey.c_str());
            } else {
                cout << "No key found for this edition. Activation aborted." << endl;
            }
            cout << "Process is done. Please look at the pop-ups and program's response, if you see succesfull messages, your Windows system is now activated and geniue!." << endl;
            return 0;
        } else {
            // error msg
            cout << "Please enter valid choice!" << endl;
            return 1;
        }
    }
    if (selection == 2){
        // Simple activation
        cout << "Please enter your key: " << endl;
        string input;
        cin >> input;
        if (!input.empty()) {
            activate(input.c_str());
        } else {
            cout << "No key entered. Activation aborted." << endl;
        }
        cout << "Process is done. Please look at the pop-ups and program's response, if you see succesfull messages, your Windows system is now activated and geniue!." << endl;
        return 0;
    }
    if (selection == 3) {
        // Helpful information
        cout << "Helpful information about zevkeygen." << endl;
        cout << "Options:" << endl;
        cout << "1. The first option is when zevkeygen activates windows for free via special keys." << endl;
        cout << "2. The second option is when zevkeygen activates windows using YOUR KEY" << endl;
        cout << "3. The third option views this message" << endl;
        cout << "Possible pop-ups during the process:" << endl;
        cout << "The first pop-up message indicating that the product key has been successfully installed, if not try again or select different edition." << endl;
        cout << "The Second pop-up message indicating that the KMS server has been set successfully, if not check your internet connection and try again." << endl;
        cout << "The third pop-up message indicating whether the activation was successful or if there are any issues, if not try again or look up the error in the issues tab in the github(https://github.com/wndkx/zevkeygen/issues/) or google it." << endl;
        cout << "If the activation is successful, the system will be considered genuine and properly activated." << endl;
        return 0;
    }
    else {
        // error msg
        cout << "Please enter valid choice!" << endl;
        return 1;
    }
        
}
