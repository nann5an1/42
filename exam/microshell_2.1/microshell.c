#include "microshell.h"

int tmp;

int ft_strlen(char *str){
    int i = 0;
    while(str[i])
        i++;
    return (i);
}

int ft_print_error(char *str){
    write(2, str, ft_strlen(str));
    return (1);
}

int exec_cd(char **argv, int i){
    if(i != 2)
        return (ft_print_error("error: cd: bad arguments \n"));
    if(chdir(argv[1]) == -1)
        return (ft_print_error("error: cd: cannot change directory to ") & ft_print_error(argv[1]) & ft_print_error("\n"));
    return (0);
}

int exec_cmd(char **argv, char **envp, int i){
    int ret;
    int pid;
    int pip = argv[i] && !strcmp("|", argv[i]);
    int fd[2];

    if(pip && pipe(fd) == -1)
        return (ft_print_error("error: fatal\n"));
    pid = fork();
    if(!pid){
        argv[i] = 0;
        if((dup2(tmp, 0) == -1)
        | (close(tmp) == -1)
        | (pip && ((dup2(fd[1], 1) == -1) | (close(fd[0] == - 1)) | (close(fd[1] == -1)))))
            return (ft_print_error("error: fatal\n"));
        execve(*argv, argv, envp);
        return (ft_print_error("error: cannot execute ") & ft_print_error(*argv) & ft_print_error("\n"));
    }
    if((!pip && dup2(0, tmp) == -1)
    | (pip && ((dup2(fd[0], tmp) == -1) | (close(fd[1]) == -1) | (close(fd[0]) == -1)))
    | (waitpid(pid, &ret, 0) == -1))
        return (ft_print_error("error: fatal\n"));
    return (WIFEXITED(ret) & WEXITSTATUS(ret));
}

int main(int argc, char **argv, char **envp){
    (void)argc;
    int ret;
    tmp = dup(0);
    int i = 0;
    while (argv[i] && argv[++i]){
        argv = argv + i;
        i = 0;
        while(argv[i] && strcmp("|", argv[i]) && strcmp(";", argv[i]))
            i++;
        if(!strcmp("cd", *argv))
            ret = exec_cd(argv, i);
        else if(i)
            ret = exec_cmd(argv, envp, i);
    }
    return ((dup2(0, tmp) == -1 && ft_print_error("error: fatal\n"))) | ret;
}