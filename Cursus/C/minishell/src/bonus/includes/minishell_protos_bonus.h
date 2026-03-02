/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_protos_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:55:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:06:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROTOS_BONUS_H
# define MINISHELL_PROTOS_BONUS_H

/* Core */

int		ft_minishell(char **envp, int debug);
void	ft_cleanup(t_data *data);

/* Search */

char	*ft_search_file(const char *dir, const char *filename, char **envp);
char	*ft_search_in_subdirs(const char *dir, const char *filename,
			char **envp);
char	*ft_search_in_dir(const char *dir, const char *filename, char **envp);
char	*ft_build_path(const char *dir, const char *entry);

/* Expansion */

int		ft_copy_literal(char **dst, char *arg, int start, int end);
int		ft_expand_exit_status(char **dst, int *j, t_data *data);
int		ft_expand_env_var(char **dst, char *arg, int *j, t_data *data);
int		ft_expand_pid(char **dst, int *j, t_data *data);
char	*ft_process_arg(char *arg, t_data *data);
char	*ft_escape_quotes(char *str);
int		ft_handle_quoted_after_dollar(char **dst, char *arg, int *j);
int		ft_expand_var(char **dst, char *arg, int *j, t_data *data);
int		ft_is_escaped(const char *s, int pos);
char	**ft_handle_env_expansion(char **argv, t_data *data);

/* Execution */

char	*ft_get_cmd_path(char *cmd, char **envp);
int		ft_finish_execution(pid_t *pids, t_cmd *cmd_list, t_data *data);
void	ft_setup_child_io(t_cmd *current, t_cmd *cmd_list);
int		ft_exec_builtin(t_cmd *cmd, t_data **data);
int		ft_is_builtin(t_cmd *cmd);
int		ft_execute_cmds(t_cmd *cmd_list, t_data **data);
int		ft_exec_bin(t_cmd *cmd);
int		ft_should_execute(t_cmd **current, t_data *data);
int		ft_execute_subshell(t_cmd *cmd, t_data **data, pid_t *pids);

/* Prompt */

char	*ft_get_directory_path(char **envp);
char	*ft_generate_prompt(char **envp);

/* Init */

int		ft_msg_start(char **envp);

/* Arg counting */

int		ft_count_args(const char *cmd);

/* Memory */

void	ft_free_matrix(char **array);
void	ft_free_matrix_size(char **array, int size);

/* Helpers */

int		ft_is_in_quotes(const char *input, int pos);

/* Input */

int		ft_read_input(char **input, t_data *data);
char	**ft_split_input(const char *input, int argc);
t_cmd	*ft_process_input(char *input, t_data *data, int debug);
int		ft_check_input_syntax(char **argv, int argc);
char	*ft_remove_quotes(const char *str);

/* Parsing */

t_cmd	*ft_parse_input(t_data *data);
int		ft_append(char **dst, const char *src);
t_cmd	*ft_create_cmd_node(int index);
void	ft_add_arg_to_cmd(t_cmd *cmd, char *arg);
void	ft_free_cmd_list(t_cmd *cmd_list);
int		ft_assign_fd(t_cmd **cmd, char *filename, char *type);
int		ft_redir(t_cmd *cmd, char **argv, int i);
int		ft_process_op(t_cmd **current_cmd, char *arg, int *cmd_index,
			t_data *data);
int		ft_process_token(t_cmd **current_cmd, char **argv, int i,
			int *cmd_index);
int		ft_has_closing_quote(const char *s, char quote);
int		ft_process_subshell(t_cmd **current_cmd, t_data *data, int *i,
			int *cmd_index);

/* ENV */

char	*ft_create_env_var(char *name, char *value);
char	**ft_dupenv(char **envp);
char	*ft_getenv(const char *name, char **envp);
char	**ft_realloc_envp(char **envp, int new_size);
int		ft_setenv(char *name, char *value, char ***envp);
int		ft_update_existing_env(char *name, char *value, char **envp);
void	ft_update_pwd_env(char *oldpwd, char *target_dir, char ***envp, int n);
char	*ft_normalize_path(const char *path);

/* Debug */

void	ft_show_debug(t_cmd *cmd_list);

/* Redirections */

int		ft_handle_infile(char *filename);
int		ft_handle_outfile(char *filename, int append);
int		ft_is_ambiguous_redirect(char *filename);
int		ft_check_ambiguous(t_cmd *cmd, char **argv, int i, char *expanded_arg);
int		ft_handle_fd_error(t_cmd *cmd, int fd_ret);
int		ft_handle_wildcard_sentinel(t_cmd *cmd, char *expanded_arg);

/* Wildcards */

int		ft_match_pattern(const char *pattern, const char *filename);
int		ft_has_wildcards(const char *str);
int		ft_count_matches(const char *pattern);
int		ft_expand_wildcard(const char *pattern, char **matches,
			int max_matches);
void	ft_sort_strings(char **arr, int size);
char	**ft_handle_wildcards(char **argv, t_data *data);
int		is_prev_redir(char **a, int idx);
int		is_prev_heredoc(char **a, int idx);
int		count_total_args(char **argv);
int		ft_process_wildcard(char *arg, char **new_argv, int *new_argc);

/* Signals */

void	sigint_handler(int sig);
void	ft_init_signals(void);

/* Builtins */

int		ft_echo(t_cmd cmd);
int		ft_cd(char **argv, char ***envp);
int		ft_pwd(t_cmd cmd);
int		ft_export(char **args, char ***envp);
int		ft_unset(char **args, char ***envp);
int		ft_env(t_cmd cmd, char **envp);
int		ft_exit(t_cmd *cmd);
int		ft_handle_builtins(t_cmd *cmd, t_data **data, t_cmd *cmd_list,
			pid_t *pids);

/* Utils */

int		ft_is_dot_or_dotdot(const char *name);

/* Heredoc */

int		ft_heredoc(const char *delimiter, t_data *data);

/* Error handling */

int		ft_handle_error(int error_code, int exit_code, char *msg, char *msg2);

#endif /* MINISHELL_PROTOS_BONUS_H */
