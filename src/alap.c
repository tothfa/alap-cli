#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char c_source_code[] =
    "#include <stdio.h>\n"
    "\n"
    "int main()\n"
    "{\n"
    "    printf(\"Hello World!\\n\");\n"
    "\n"
    "    return 0;\n"
    "}\n";

const char py_source_code[] =
    "#!/usr/bin/env python3\n"
    "\n"
    "\n"
    "def main():\n"
    "    print(\"Hello World!\")\n"
    "\n"
    "if __name__ == \"__main__\":\n"
    "    main()\n";

const char java_source_code[] =
    "public class Main\n"
    "{\n"
    "    public static void main(String[] args)\n"
    "    {\n"
    "        System.out.println(\"Hello World!\");\n"
    "    }\n"
    "}\n";

const char bash_source_code[] =
    "#!/usr/bin/env bash\n"
    "\n"
    "echo \"Hello World!\"\n";

const char version[] =
    "alap v0.3.0\n";

const char help_text[] =
    "alap v0.3.0\n"
    "\n"
    "USAGE:\n"
    "  alap <template_id> [OPTION]\n"
    "\n"
    "TEMPLATES:\n"
    "  c      C source code [main.c]\n"
    "  java   Java source code [Main.java]\n"
    "  py     Python source code [main.py]\n"
    "  sh     Bash script [main.sh]\n"
    "\n"
    "OPTIONS:\n"
    "  -h, --help     Show this help message and exit\n"
    "  -v, --version  Show version information\n"
    "  --stdout       Print output to stdout instead of creating a file\n"
    "\n";

typedef struct
{
    const char *id;
    const char *lang_filename;
    const char *source_code;
} Templates;

const Templates templates[] = 
    {
    {"c", "main.c", c_source_code},
    {"java", "Main.java", java_source_code},
    {"py", "main.py", py_source_code},
    {"sh", "main.sh", bash_source_code}
    };

const int template_count = sizeof(templates) / sizeof(Templates);

int file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");

    if (fp != NULL)
    {
        fclose(fp);
        return 1;
    }

    return 0;
}

int get_template_index(const char *template_id)
{
    for (int i = 0; i < template_count; i++)
    {
        if (strcmp(template_id, templates[i].id) == 0)
        {
            return i;
        }
    }

    return -1;
}

void generate_file(const char *template_id)
{
    int index = get_template_index(template_id);

    const char *filename = templates[index].lang_filename;
    const char *source_code = templates[index].source_code;

    if (file_exists(filename))
    {
        printf("# [%s] already exists.\n", filename);
        return;
    }

    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Error creating the file!\n");
        return;
    }

    fprintf(fp, "%s", source_code);

    fclose(fp);

    printf("# [%s] was created.\n", filename);
}

void print_out_source_code(const char *template_id)
{
    int t_index = get_template_index(template_id);

    fprintf(stdout, "%s", templates[t_index].source_code);
}

int main(int argc, char *argv[])
{
    if (argc < 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        printf("%s", help_text);
        return 0;
    }

    if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
    {
        printf("%s", version);
        return 0;
    }

    char *template_id = argv[1];
    int t_index = get_template_index(template_id);

    if (t_index == -1)
    {
        printf("Unknown template: %s\n", template_id);
        printf("Use -h or --help switch for help.\n");
        return 1;
    }

    if (argc == 3)
    {
        char *option_id = argv[2];
        if (strcmp(option_id, "--stdout") == 0)
        {
            print_out_source_code(template_id);
            return 0;
        }
        else
        {
            printf("Unknown option: %s\n", option_id);
            printf("Use -h or --help switch for help.\n");
            return 1;
        }
    }

    if (argc > 3)
    {
        printf("Too many arguments.\n");
        printf("Use -h or --help switch for help.\n");
        return 1;
    }

    generate_file(template_id);

    return 0;
}

