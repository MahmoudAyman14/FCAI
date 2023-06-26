from tkinter import *
from PIL import ImageTk, Image
import time

graph = {
    'A': [('b', 20), ('c', 19), ('D', 7), ('f', 18)],
    'D': [('c', 5), ('f', 9), ('b', 12), ('A', 7)],
    'b': [('c', 6), ('f', 7), ('D', 12), ('A', 20)],
    'c': [('f', 6), ('b', 6), ('A', 19), ('D', 5)],
    'f': [('b', 7), ('c', 6), ('D', 9), ('A', 18)]
}

H_table = {
    'A': 4,
    'b': 6,
    'c': 5,
    'D': 2,
    'f': 3
}

visited = []


def path_f_cost(path, H_table):
    g_cost = 0
    for node, cost in path:
        g_cost += cost
    last_node = path[-1][0]
    h_cost = H_table[last_node]
    f_cost = g_cost + h_cost
    return f_cost, g_cost


def a_star_search(graph, start, H_table):
    queue = [[(start, 0)]]
    shortest_path = None
    while queue:
        queue.sort(key=lambda path: path_f_cost(path, H_table)[0])
        path = queue.pop(0)
        node = path[-1][0]
        if node in visited:
            continue
        visited.append(node)
        adjacent_nodes = graph.get(node, [])
        for (node2, cost) in adjacent_nodes:
            if node2 in visited:
                continue
            new_path = path.copy()
            new_path.append((node2, cost))
            queue.append(new_path)
            if shortest_path is None or path_f_cost(new_path, H_table)[0] < path_f_cost(shortest_path, H_table)[0]:
                shortest_path = new_path
    if set(visited) == set(graph.keys()):
        count = 0
        i = 0
        for Node in visited:
            if i == 0:
                Adjacent_nodes = graph.get(Node, [])
                i += 1
                continue
            for n, cost in Adjacent_nodes:
                if n == Node:
                    count += cost
            i += 1
            if i == len(visited):
                count += H_table[Node]
            Adjacent_nodes = graph.get(Node, [])

        return count

def move_drone(canvas, drone_img, start, end):
    x1, y1 = node_positions[start]
    x2, y2 = node_positions[end]
    dx, dy = x2-x1, y2-y1
    distance = (dx**2 + dy**2)**0.5
    steps = int(distance/5) + 1
    vx, vy = dx/steps, dy/steps
    x, y = x1, y1
    for i in range(steps):
        x += vx
        y += vy
        canvas.coords(drone_img, x, y)
        canvas.update()
        time.sleep(0.1)
    canvas.delete(drone_img)
    drone_img = canvas.create_image(node_positions[end], image=droneImage, tags="drone")
    return drone_img




def run_a_star_search():
    start_node = selected.get()
    shortest_path = a_star_search(graph, start_node, H_table)
    if shortest_path:
        result_label.config(text=f"Shortest path: {visited}\nTotal cost: {shortest_path}")
        drone_img = None
        node_items = {}
        for node, position in node_positions.items():
            x, y = position
            node_items[node] = canvas.create_oval(x-node_radius, y-node_radius, x+node_radius, y+node_radius, fill='grey', outline='black')
            canvas.create_text(x, y, text=node, font=("Arial", 16))
            
        canvas.itemconfig(node_items[start_node], fill='red')
        canvas.create_image(node_positions[start_node], image=BoomImage)

        for i in range(1, len(visited)):
            node = visited[i]
            if drone_img:
                canvas.delete(drone_img)
            drone_img = canvas.create_image(node_positions[node], image=droneImage, tags="drone")
            
            time.sleep(1)
            drone_img = move_drone(canvas, drone_img, visited[i-1], node)
            canvas.create_image(node_positions[node], image=BoomImage)
            canvas.itemconfig(node_items[node], fill='red')
            #canvas.itemconfig(node_items[visited[i-1]], fill='grey')







# GUI code
canvas_width = 500
canvas_height = 500
node_radius = 20
node_positions = {
    'A': (100, 100),
    'b': (300, 100),
    'c': (200, 150),
    'D': (100, 300),
    'f': (300, 300)
}



root = Tk()
root.title("Military Drone")
root.iconbitmap(r"C:\Users\dell\OneDrive\Desktop\drone.ico")
canvas = Canvas(root, width=canvas_width, height=canvas_height, bg='white')
canvas.pack()

drone = Image.open(r"C:\Users\dell\OneDrive\Desktop\drone.png")
width, height = drone.size
drone = drone.resize((int(width/10), int(height/10)), Image.ANTIALIAS)
droneImage = ImageTk.PhotoImage(drone)

Boom = Image.open(r"C:\Users\dell\OneDrive\Desktop\pngimg.com - explosion_PNG15402.png")
width2, height2 = Boom.size
Boom = Boom.resize((int(width2/10), int(height2/10)), Image.ANTIALIAS)
BoomImage = ImageTk.PhotoImage(Boom)


for node, position in node_positions.items():
    x, y = position
    canvas.create_oval(x-node_radius, y-node_radius, x+node_radius, y+node_radius, fill='grey', outline='black')
    canvas.create_image(0, 0, anchor=NW, image=droneImage)
    canvas.create_text(x, y, text=node, font=("Arial", 16))

for node, edges in graph.items():
    x1, y1 = node_positions[node]
    for (node2, _) in edges:
        x2, y2 = node_positions[node2]
        canvas.create_line(x1+node_radius/2, y1+node_radius/2, x2+node_radius/2, y2+node_radius/2)
selected = StringVar(root)
selected.set('A') # default value
dropdown_label = Label(root, text="Select start node:")
dropdown_label.pack(pady=10)
dropdown_menu = OptionMenu(root, selected, *node_positions.keys())
dropdown_menu.pack()

search_button = Button(root, text="Run A* Search", command=run_a_star_search)
search_button.pack(pady=10)

result_label = Label(root, text="")
result_label.pack(pady=10)


root.mainloop()

