# 📝 To-Do List Manager in C

A simple command-line To-Do List application written in C that allows users to register, log in, and manage their daily tasks.

---

## 🚀 Features

- User Registration & Login  
- Add Tasks  
- View Tasks  
- Mark Tasks as Completed  
- Menu-driven interface  

---

## 📂 Project Structure

.
├── main.c
├── task.c
├── task.h
├── user.c
├── user.h

---

## ⚙️ How It Works

1. User selects:
   - Login
   - Register

2. After login:
   - Add new tasks
   - View all tasks
   - Mark tasks as completed

3. Tasks are stored in a linked list (in memory).

---

## 🛠️ Compilation & Run

Compile:
gcc main.c task.c user.c -o todo

Run:
./todo

---

## ⚠️ Limitations

- No file storage (data lost after exit)
- No password encryption
- Fixed user limit

---

## 🔮 Future Improvements

- Add file storage
- Password encryption
- Better UI
- Search & delete tasks

---

## 👨‍💻 Author

Abhishek
