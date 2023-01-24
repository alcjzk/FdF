make fclean
git checkout --orphan submit &&
git reset &&
rm -rf libft .vscode .github .gitmodules README.md create_submission.sh &&
git clone https://github.com/alcjzk/libft.git libft &&
rm -rf libft/.github libft/README.md libft/.git &&
git add . &&
git commit -m "Initial commit"