from PIL import Image

def setpixel(x,y,img):
    img.putpixel((x,y), (255,0,0))
    img.save('sqr.png')
    return img

def plotaSimetricos(a,b,xc,yc,img):
    img=setpixel((a+xc),(b+yc),img)
    img=setpixel((a+xc),(-b+yc),img)
    img=setpixel((-a+xc),(b+yc),img)
    img=setpixel((-a+xc),(-b+yc),img)
    img=setpixel((b+xc),(a+yc),img)
    img=setpixel((b+xc),(-a+yc),img)
    img=setpixel((-b+xc),(a+yc),img)
    img=setpixel((-b+xc),(-a+yc),img)
    return img

def circle(R,xc,yc):
    img=Image.new('RGB',(400,400))
    x=0
    y=R
    p=3-(2*R)
    img=plotaSimetricos(x,y,xc,yc,img)
    while x<y:
        if p<0: 
            p+=4*x+6
        else: 
            p+=4*(x-y)+10
            y=y-1
        x=x+1
        img=plotaSimetricos(x,y,xc,yc,img)
    return img

image=circle(100,200,200)
image.show()