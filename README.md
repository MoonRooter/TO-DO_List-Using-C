# 📝 Advanced To-Do List Manager in C

A powerful **command-line To-Do List Manager** written in C with user authentication and persistent task storage.

---

## 🚀 Features

- 👤 User Registration & Login
- ➕ Add Tasks
- 📋 View Tasks
- ✅ Mark Tasks as Completed
- ❌ Delete Specific Task
- 🧹 Delete All Tasks
- 💾 Save & Load Tasks (File Handling)
- 🔐 Multi-user support

---

## 📂 Project Structure

```
ToDo-Manager/
│
├── main.c        # Entry point of program
├── task.c        # Task operations (CRUD)
├── task.h        # Task declarations
├── user.c        # User system (login/register)
├── user.h        # User declarations
```

---

## ⚙️ How It Works

1. User logs in or registers.
2. Tasks are loaded from storage.
3. User can:
   - Add tasks
   - View tasks
   - Mark tasks completed
   - Delete tasks
4. On exit, tasks are saved automatically.

---

## 🛠️ Compilation & Run

### Compile
```bash
gcc main.c -o todo
```

### Run
```bash
./todo
```

---

## 💡 Example Menu

```
====== TO-DO LIST ======
User: abhishek

1. Add Task
2. View Tasks
3. Mark Completed
4. Delete Task
5. Delete All Tasks
6. Exit
```

---

## 🔧 Technologies Used

- C Programming
- Linked List (Dynamic Memory)
- File Handling
- Modular Programming

---

## ⚠️ Important Notes

- Uses dynamic memory (malloc/free)
- Tasks persist using file storage
- Input validation handled for stability

---

## 🔮 Future Improvements

- 🔐 Password encryption
- 🌐 GUI version
- 🔍 Search & filter tasks
- 📊 Task priority system

---

## 👨‍💻 Author

**Abhishek**

---

⭐ If you like this project, give it a star on GitHub!
