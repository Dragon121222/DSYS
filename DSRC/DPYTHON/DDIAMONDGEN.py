import bpy

def diamondGen(n,d,x=0,y=0,z=0): 
    if(d==1):
        for i in range(n):
            bpy.ops.mesh.primitive_cube_add(size=0.5, location=( i+x, 0+y, 0+z))
            bpy.ops.mesh.primitive_cube_add(size=0.5, location=(-i+x, 0+y, 0+z))
    if(d==2):
        for j in range(n):        
            diamondGen(n-j,1,0+x,j+y,z)
            diamondGen(n-j,1,0+x,-j+y,z)
    if(d==3):
        for k in range(n):        
            diamondGen(n-k,2,0+x,0+y,k+z)
            diamondGen(n-k,2,0+x,0+y,-k+z)
    if(d==4):
        for l in range(n): 
            diamondGen(n-l,3,l*2*n+x,0+y,0+z)
            diamondGen(n-l,3,-l*2*n+x,0+y,-0+z)
    if(d==5):
        for m in range(n): 
            diamondGen(n-m,4,x,m*2*n+y,0+z)
            diamondGen(n-m,4,x,-m*2*n+y,-0+z)
    if(d==6):
        for o in range(n): 
            diamondGen(n-o,5,x,y,o*2*n++z)
            diamondGen(n-o,5,x,y,-o*2*n++z)            

diamondGen(5,6)