# Client Management System

This is a simple client management system implemented in C++ using linked lists. The program allows you to perform basic operations such as registering new clients, deleting clients, querying clients by CPF (Brazilian tax identification number), and displaying all registered clients.

## Features

- **Register Client**: Add a new client with their name, CPF, and phone number.
- **Delete Client**: Remove a client from the list by providing their CPF.
- **Display Clients**: Display all registered clients with their details.
- **Query Client by CPF**: Search and display the details of a client by their CPF.
- **Memory Management**: The program ensures that memory is properly released after use.

## Code Overview

The program uses a **singly linked list** structure to store client information. Each client is represented by a `Cliente` structure, which contains the following fields:
- `nome`: Name of the client
- `cpf`: CPF of the client
- `celular`: Cell phone number of the client
- `proximo`: Pointer to the next client in the listi

### Functions

1. **`inicializar()`**: Initializes the list by returning `nullptr`.
2. **`cadastrarCliente()`**: Registers a new client at the end of the list.
3. **`excluirCliente()`**: Deletes a client from the list using their CPF.
4. **`exibirClientes()`**: Displays all registered clients.
5. **`consultarClientePorCPF()`**: Searches for and displays a client by their CPF.
6. **`liberarLista()`**: Frees up the memory allocated for the list.

### Main Menu

The program offers a simple interactive menu to the user with the following options:
1. Register a new client
2. Delete a client by CPF
3. Display all clients
4. Search for a client by CPF
5. Exit the program
