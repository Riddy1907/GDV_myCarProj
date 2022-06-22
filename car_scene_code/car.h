enum caps {NONE = 0, BOTTOM, TOP, BOTH};

// draw a cylinder with caps
void cylinderdisk(GLUquadric *qobj, double innerRadius, double outerRadius, double height, int slices, caps c = BOTH);

// draw a parallelepiped whith dimensions lx ly lz and centered at [cx, cy, cz]
void parallelepiped(float lx, float ly, float lz, float cx, float cy, float cz);

void bodycar();
void tirezp();
void light();
void boot_door();
void wiper1();
void wiper2();
extern GLuint tex_wheel;
