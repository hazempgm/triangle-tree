import sys

def generate_triangle_tree(levels, filename):
    with open(filename, 'w') as file:
        for i in range(levels):
            nodes = ' '.join(str(j + 1) for j in range(i+1))
            file.write(nodes + '\n')

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python generate_triangle_tree.py <levels> <output_file>")
        sys.exit(1)

    levels = int(sys.argv[1])
    output_file = sys.argv[2]

    generate_triangle_tree(levels, output_file)
