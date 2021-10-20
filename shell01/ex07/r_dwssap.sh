cat /etc/passwd | grep -v '\#' | sed -n 'n;p' | sed 's/:.*//g' | rev | sort -r | awk 'NR>= ENVIRON["FT_LINE1"] && NR<= ENVIRON["FT_LINE2"]' | tr '\n' "," | sed 's/,$/./' | sed 's/,/, /g' | tr -d '\n'
