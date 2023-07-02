from tkinter import *
from tkinter import messagebox as mb
import ctypes, os

def isAdmin():
    try:
        is_admin = (os.getuid() == 0)
    except AttributeError:
        is_admin = ctypes.windll.shell32.IsUserAnAdmin() != 0
    return is_admin


root = Tk()
root.title("ZevKeyGen")
root.resizable(False, False)
root.geometry("300x300")
main_l = Label(text="ZevKeyGen v1.0.1")
main_l.pack()
keys = {"Windows 10/11 Pro": "W269N-WFGWX-YVC9B-4J6C9-T83GX",
        "Windows 10/11 Pro N": "MH37W-N47XK-V7XM9-C7227-GCQG9",
        "Windows 10/11 Pro for Workstations": "NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J",
        "Windows 10/11 Pro for Workstations N": "9FNHH-K3HBT-3W4TD-6383H-6XYWF",
        "Windows 10/11 Pro Education": "6TP4R-GNPTD-KYYHQ-7B7DP-J447Y",
        "Windows 10/11 Pro Education N": "YVWGF-BXNMC-HTQYQ-CPQ99-66QFC",
        "Windows 10/11 Education": "NW6C2-QMPVW-D7KKK-3GKT6-VCFB2",
        "Windows 10/11 Education N": "2WH4N-8QGBV-H22JP-CT43Q-MDWWJ",
        "Windows 10/11 Enterprise": "NPPR9-FWDCX-D2C8J-H872K-2YT43",
        "Windows 10/11 Enterprise N": "DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4",
        "Windows 10/11 Enterprise G": "YYVX9-NTFWV-6MDM3-9PT4T-4M68B",
        "Windows 10/11 Enterprise G N": "44RPN-FTY23-9VTTB-MP9BX-T84FV",
        "Windows 10 Enterprise LTSC 2019/2021": "M7XTQ-FN8P6-TTKYV-9D4CC-J462D",
        "Windows 10 Enterprise N LTSC 2021/2019": "92NFX-8DJQP-P6BBQ-THF9C-7CG2H",
        "Windows 10 Enterprise LTSB 2016": "DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ",
        "Windows 10 Enterprise N LTSB 2016": "QFFDN-GRT3P-VKWWX-X7T3R-8B639",
        "Windows 10 Enterprise 2015 LTSB": "WNMTR-4C88C-JK8YV-HQ7T2-76DF9",
        "Windows 10 Enterprise 2015 LTSB N": "2F77B-TNFGY-69QQF-B8YKP-D69TJ",
        "Windows 8.1 Pro": "GCRJD-8NW9H-F2CDX-CCM8D-9D6T9",
        "Windows 8.1 Pro N": "HMCNV-VVBFX-7HMBH-CTY9B-B4FXY",
        "Windows 8.1 Enterprise": "MHF9N-XY6XB-WVXMC-BTDCT-MKKG7",
        "Windows 8.1 Enterprise N": "TT4HM-HN7YT-62K67-RGRQJ-JFFXW",
        "Windows 8 Pro": "NG4HW-VH26C-733KW-K6F98-J8CK4",
        "Windows 8 Pro N": "XCVCF-2NXM9-723PB-MHCB7-2RYQQ",
        "Windows 8 Enterprise": "JMNMF-RHW7P-DMY6X-RF3DR-X2BQT",
        "Windows 8 Enterprise N": "TT4HM-HN7YT-62K67-RGRQJ-JFFXW",
        "Windows 7 Professional": "FJ82H-XT6CR-J8D7P-XQJJ2-GPDD4",
        "Windows 7 Professional N": "MRPKT-YTG23-K7D7T-X2JMM-QY7MG",
        "Windows 7 Professional E": "W82YF-2Q76Y-63HXB-FGJG9-GF7QX",
        "Windows 7 Enterprise": "33PXH-7Y6KF-2VJC9-XBBR8-HVTHH",
        "Windows 7 Enterprise N": "YDRBP-3D83W-TY26F-D46B2-XCKRJ",
        "Windows 7 Enterprise E": "C29WB-22CC8-VJ326-GHFJW-H9DH4",
        "Windows Vista Business": "YFKBB-PQJJV-G996G-VWGXY-2V3X8",
        "Windows Vista Business N": "HMBQG-8H2RH-C77VX-27R82-VMQBT",
        "Windows Vista Enterprise": "VKK3X-68KWM-X2YGT-QR4M6-4BWMV",
        "Windows Vista Enterprise N": "VTC42-BM838-43QHV-84HX6-XJXKV"}

default_l = Label(text="Default activation:")
select_l = Label(text="Select windows edition:")
win = StringVar(root)
def activate_from_win():
    os.system(f"slmgr/ipk {keys[win.get()]}")
    os.system("slmgr /skms kms.digiboy.ir")
    os.system("slmgr /ato")
default_l.pack()
select_l.pack()
w = OptionMenu(root, win, *list(keys.keys()))
w.pack()
activate = Button(text="Activate!", command=activate_from_win)
activate.pack()
def activate_from_key():
    os.system(f"slmgr /ipk {a_key.get()}")
key_a = Label(text="Activate from a key:")
key_l = Label(text="Key:")
a_key = Entry(width=30)
activate_from_k = Button(text="Activate from my key!", command=activate_from_key)
key_a.pack()
key_l.pack()
a_key.pack()
activate_from_k.pack()
if __name__ == "__main__":
    if isAdmin():
        root.mainloop()
    else:
        mb.showerror(title="ZevKeyGen", message="Admin required!")
