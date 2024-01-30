import json,copy
from tkinter import *
from tkinter import messagebox

def save(user_data:dict):
    with open("user_data.json",mode="w") as file:
        json.dump(user_data,file)

def window_quit():
    if old_user_data != new_user_data:
        if messagebox.askyesno("Exit","Do you want to save your data?"):
            save(new_user_data)
    window.destroy()

def click_save_button():
    global old_user_data
    try:
        save(new_user_data)
        old_user_data = copy.deepcopy(new_user_data)
        messagebox.showinfo("Message","Save data successfully")
    except:
        messagebox.showerror("Message","Failed to save data,please check your user_data.json!")

def show_passwd():
    passwd[0] = passwd_entry_box.get()
    passwd[1] = not passwd[1]
    if passwd[1]:
        passwd_entry_box.configure(show="")
        passwd_show_button.configure(text="Hide")
    else:
        passwd_entry_box.configure(show="*")
        passwd_show_button.configure(text="Show")

def user_ok():
    new_user_data["std_id"] = id_entry_box.get()
    new_user_data["password"] = passwd_entry_box.get()

def plan_course():
    course_name_label.configure(text="Plan courses")
    course_list_box.delete(0,END)
    for course in new_user_data["course"]["a"]:
        course_list_box.insert(0,"%s_%s"%(course["course_id"],course["course_index"]))

def free_course():
    course_name_label.configure(text="Free courses")

#load the data,if it exists
try:
    with open("user_data.json",mode="r") as file:
        old_user_data = json.load(file)
except:
    old_user_data = {"std_id":"","password":"","course":{"a":[],"b":[]}}

new_user_data = copy.deepcopy(old_user_data)
passwd = [new_user_data["password"],False]
size = [640,480]

#Create a gui
window = Tk()
window.title("Initialize")
window.iconbitmap("favicon.ico")
window.geometry("%dx%d"%(size[0],size[1]))
window.protocol("WM_DELETE_WINDOW",window_quit)

#Labels
id_label = Label(window,text="Student ID")
passwd_label = Label(window,text="Password")
course_name_label = Label(window)

#Entries
id_entry_box = Entry(window,width=20)
passwd_entry_box = Entry(window,width=20,show="*")

#Buttons
passwd_show_button = Button(window,text="Show",command=show_passwd)
save_button = Button(window,text="Save",width=20,height=2,command=click_save_button)
user_ok_button = Button(window,text="OK",width=7,height=1,command=user_ok)

#Listbox
course_list_box = Listbox(window,height=15,font=("TkDefaultFont",18))

#Menus
window_menu = Menu(window)
window_menu_list = Menu(window_menu,tearoff=False)
window_menu.add_cascade(label="Course type",menu=window_menu_list)
window_menu_list.add_command(label="Plan course",command=plan_course)
window_menu_list.add_command(label="Free course",command=free_course)
plan_course()

#Insert and place
id_entry_box.insert(0,new_user_data["std_id"])
passwd_entry_box.insert(0,passwd[0])

id_label.place(x=size[0]-290,y=50)
id_entry_box.place(x=size[0]-220,y=50)
passwd_label.place(x=size[0]-285,y=85)
passwd_entry_box.place(x=size[0]-220,y=85)
passwd_show_button.place(x=size[0]-70,y=80)
user_ok_button.place(x=size[0]-175,y=125)
save_button.place(x=size[0]-225,y=size[1]-120)
course_name_label.place(x=50,y=10)
course_list_box.place(x=50,y=30)

window.config(menu=window_menu)

#keep the gui active
window.mainloop()