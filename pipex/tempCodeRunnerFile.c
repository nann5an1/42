char* ft_split(char* )
// {
    
// }

// char* programSearch(char* cmd, char** envp)
// {
//     while(*envp != '\0')
//     {
//          if(ft_strncmp(envp, "PATH", 5) == 0)
//             return (*envp) + 5;
//         *envp++;
//     }
//     return (NULL);
// }

// void exec_command(char* cmd, char** envp)
// {    
//     // char *const av[] = ft_split(cmd);
//     const char* programDir = programSearch(cmd, *envp);
//     const char* envp[] = 
//     {
//         "PATH=/bin:/usr/bin",
//         "HOME=/home/nsan/"
//     }; 
//     if(execve(programDir, cmd, envp) < 0)
//         perror("Error Executing");
//     execve(programDir, cmd, envp);
//     printf("Execute the command");         
// }
