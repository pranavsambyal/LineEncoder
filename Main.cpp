#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.1f, 0.22f, 1.0f);\n"
"}\n\0";
const char* fragmentShader2Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0";
const char* fragmentShader3Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0";
using namespace std;

vector<int> str2vect(string s)
{
    vector<int> v;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '-')
        {
            v.push_back(s[i] - 48);
        }
        else
        {
            i++;
            v.push_back((s[i] - 48) * -1);
        }
    }
    return v;
}

void printvect(vector<int>& v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

string randomInput(int l, int prob)
{
    string s;
    if (prob == 1)
    {
        const char chars[2] = { '0', '1' };
        int sz = 2;
        for (int i = 0; i < l; i++)
        {
            int Index = rand() % sz;
            s.push_back(chars[Index]);
        }
    }
    else if (prob == 2)
    {
        const char chars[4] = { '0', '1', '0', '0' };
        int sz = 4;
        for (int i = 0; i < l; i++)
        {
            int Index = rand() % sz;
            s.push_back(chars[Index]);
        }
    }
    else if (prob == 3)
    {
        if (l > 4) {
            const char chars[4] = { '1', '1', '1', '1' };
            int sz = 5;
            for (int i = 0; i < l; i++)
            {
                int Index = rand() % sz;
                if (Index == 4) {
                    if ((l - i) >= 8) 
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            s.push_back('0');
                        }
                        i += 7;
                    }
                    else if((l - i) >= 4)
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            s.push_back('0');
                        }
                        i += 3;
                    }
                    else
                    {
                        s.push_back('0');
                    }
                }
                else
                {
                    s.push_back(chars[Index]);
                }
            }
        }
        else
        {
            cout << "\tSize is <=4, Cant add 4/8 zeros\n\tUsing 2nd option for the given input\n";
            const char chars[4] = { '0', '1', '0', '0' };
            int sz = 4;
            for (int i = 0; i < l; i++)
            {
                int Index = rand() % sz;
                s.push_back(chars[Index]);
            }
        }
    }
    return s;
}

vector<int> nrzl(int logic, vector<int>& a)
{
    vector<int> r;
    if (logic == 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 1)
            {
                r.push_back(1);
            }
            else
            {
                r.push_back(-1);
            }
        }
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 0)
            {
                r.push_back(1);
            }
            else
            {
                r.push_back(-1);
            }
        }
    }
    return r;
}

vector<int> nrzi(int logic, vector<int>& a)
{
    vector<int> r = a;
    if (logic == 0)
    {
        r.insert(r.begin(), -1);
        for (int i = 1; i < r.size(); i++)
        {

            if (a[i - 1] == 1)
            {
                if (r[i - 1] == 0 || r[i - 1] == -1)
                {
                    r[i] = (1);
                }
                else
                {
                    r[i] = (-1);
                }
            }
            else
            {
                if (r[i - 1] == 1)
                {
                    r[i] = (1);
                }
                else
                {
                    r[i] = (-1);
                }
            }
        }
    }
    else
    {
        r.insert(r.begin(), -1);
        for (int i = 1; i < r.size(); i++)
        {

            if (a[i - 1] == 1)
            {
                if (r[i - 1] == 0 || r[i - 1] == -1)
                {
                    r[i] = (-1);
                }
                else
                {
                    r[i] = (1);
                }
            }
            else
            {
                if (r[i - 1] == 1)
                {
                    r[i] = (-1);
                }
                else
                {
                    r[i] = (1);
                }
            }
        }
    }
    r.erase(r.begin());
    return r;
}
vector<int> rz(int logic, vector<int>& a)
{
    vector<int> r;
    if (logic == 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 1)
            {
                r.push_back(1);
                r.push_back(0);
            }
            else
            {
                r.push_back(-1);
                r.push_back(0);
            }
        }
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 0)
            {
                r.push_back(1);
                r.push_back(0);
            }
            else
            {
                r.push_back(-1);
                r.push_back(0);
            }
        }
    }
    return r;
}
vector<int> manc(int logic, vector<int>& a)
{
    vector<int> r;
    if (logic == 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 1)
            {
                r.push_back(1);
                r.push_back(-1);
            }
            else
            {
                r.push_back(-1);
                r.push_back(1);
            }
        }
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 0)
            {
                r.push_back(1);
                r.push_back(-1);
            }
            else
            {
                r.push_back(-1);
                r.push_back(+1);
            }
        }
    }
    return r;
}
vector<int> dmanc(int logic, vector<int>& a)
{
    vector<int> r;
    r.push_back(1);
    if (logic == 0)
    {
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i-1] == 1)
            {
                if (r.back() == 1)
                {
                    r.push_back(1);
                    r.push_back(-1);
                }
                else
                {
                    r.push_back(-1);
                    r.push_back(1);
                }
            }
            else
            {
                if (r.back() == 1)
                {
                    r.push_back(-1);
                    r.push_back(1);
                }
                else
                {
                    r.push_back(1);
                    r.push_back(-1);
                }
            }
        }
    }
    else
    {
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i - 1] == 0)
            {
                if (r.back() == 1)
                {
                    r.push_back(1);
                    r.push_back(-1);
                }
                else
                {
                    r.push_back(-1);
                    r.push_back(1);
                }
            }
            else
            {
                if (r.back() == 1)
                {
                    r.push_back(-1);
                    r.push_back(1);
                }
                else
                {
                    r.push_back(1);
                    r.push_back(-1);
                }
            }
        }
    }
    r.erase(r.begin());
    return r;
}
vector<int> ami(int logic, vector<int>& a)
{
    vector<int> r;
    int prev = -1;
    if (logic == 0)
    {
        
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 0) {
                r.push_back(0);
            }
            else {
                prev = prev * -1;
                r.push_back(prev);
            }
        } 
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 1) {
                r.push_back(0);
            }
            else {
                prev = prev * -1;
                r.push_back(prev);
            }
        }

    }

    return r;
}

vector <int> b45(vector<int>&a)
{
    int y = 0;
    int s = 0;
    vector<int> r;
    for (int i = 0; i < 4*(a.size()/4); i++)
    {
        s = s*10 + a[i];
        y++;
        if (y == 4) 
        {
            //cout << s << endl;
            pair<int, vector<int>> table[16];
            table[0].first = 0;
            table[0].second = { 1,1,1,1,0 };

            table[1].first = 1;
            table[1].second = { 0,1,0,0,1 };
            
            table[2].first =  10 ;
            table[2].second = { 1,0,1,0,0 };
            
            table[3].first = 11;
            table[3].second = { 1,0,1,0,1 };
            
            table[4].first = 100;
            table[4].second = { 0,1,0,1,0 };
            
            table[5].first = 101 ;
            table[5].second = { 0,1,0,1,1 };
            
            table[6].first = 110;
            table[6].second = { 0,1,1,1,0 };
            
            table[7].first = 111 ;
            table[7].second = { 0,1,1,1,1 };
            
            table[8].first =  1000 ;
            table[8].second = { 1,0,0,1,0 };

            table[9].first =  1001 ;
            table[9].second = { 1,0,0,1,1 };
            
            table[10].first =  1010;
            table[10].second = { 1,0,1,1,0 };

            table[11].first = 1011 ;
            table[11].second = { 1,0,1,1,1 };

            table[12].first =  1100 ;
            table[12].second = { 1,1,0,1,0 };

            table[13].first =  1101;
            table[13].second = { 1,1,0,1,1 };

            table[14].first = 1110 ;
            table[14].second = { 1,1,1,0,0 };

            table[15].first = 1111;
            table[15].second = { 1,1,1,0,1 };

            for(int i=0;i<16;i++)
            {
                if (table[i].first == s)
                {
                    for (int x : table[i].second)
                    {
                        //cout << x;
                        r.push_back(x);
                    }
                    //cout << endl;
                }
            }
            y = 0;
            s = 0;
        }
    }
    for (int i = 0; i < (a.size() % 4); i++)
    {
        r.push_back(a[(4 * (a.size() / 4)) + i]);
    }
    return r;
}
vector <int> b8zs(vector<int>& a)
{
    vector<int> b=ami(0,a);
    int prev = 1;
    int count = 0;
    int s = 0;
    vector<int> r;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == 0)
        {
            
            count = 1;
            //cout << i;
            //cout<<"   Count:"<<count<<endl;
            for (int j = 1; ((j < 8)&&((j+i)<b.size())); j++)
            {
                if (b[i + j] == 0)
                {
                    count++;
                    //cout << "    Count:" << count <<"Val at i="<<i+j<<"Is "<< b[i + j] << endl;
                }
                else
                {
                    break;
                }
            }
            if (count == 8)
            {
                    //cout << "Count is 8 here" << endl;
                    r.push_back(0);
                    r.push_back(0);
                    r.push_back(0);
                    r.push_back(prev);
                    prev = prev * -1;
                    r.push_back(prev);
                    r.push_back(0);
                    r.push_back(prev);
                    prev = prev * -1;
                    r.push_back(prev);
                    i += 7;
                    count = 0;
            }
            else
            {
                r.push_back(b[i]);
            }

        }
        else
        {
            prev = b[i];
            r.push_back(b[i]);
        }
    }
    return r;
}
vector <int> hdb3(vector<int>& a)
{
    vector<int> b = ami(0, a);
    int prev = 1;
    int parity = 0;
    int one = 0;
    int count = 0;
    vector<int> r;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i]==0)
        {
            count = 1;
            //cout << i;
            //cout << "  Count:" << count << endl;
            for (int j = 1; ((j < 4) && ((j + i) < b.size())); j++)
            {
                if (b[i + j] == 0)
                {
                    count++;
                    //cout << "   Count:" << count << "Val at i=" << i + j << "Is " << b[i + j] << endl;
                }
                else
                {
                    break;
                }
            }
            if (count == 4)
            {
                //cout <<"    Count is 4 here" << endl;
                if(parity==1)
                {
                    //cout << "parity==" << parity<<endl;
                    r.push_back(0);
                    r.push_back(0);
                    r.push_back(0);
                    r.push_back(prev);
                    i += 3;
                    parity = 0;
                }
                else if(parity == 0)
                {
                    //cout << "parity==" << parity << endl;
                    prev = prev * -1;
                    r.push_back(prev);
                    r.push_back(0);
                    r.push_back(0);
                    r.push_back(prev);
                    i += 3;
                }
                
                count = 0;
            }
            else
            {
                r.push_back(b[i]);
            }

        }
        else
        {
            prev = b[i];
            r.push_back(b[i]);
            one++;
            parity = one%2;
        }
    }
    return r;
}

string findLongestPalindrome(string X, string Y, int m, int n, vector<vector<int>>& lookup)
{
    if (m == 0 || n == 0) {
        return string("");
    }
    if (X[m - 1] == Y[n - 1])
    {
        return findLongestPalindrome(X, Y, m - 1, n - 1, lookup) + X[m - 1];
    }
    if (lookup[m - 1][n] > lookup[m][n - 1]) {
        return findLongestPalindrome(X, Y, m - 1, n, lookup);
    }
    return findLongestPalindrome(X, Y, m, n - 1, lookup);
}
int LCSLength(string X, string Y, int n, vector<vector<int>>& lookup)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }
            else {
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
            }
        }
    }
    return lookup[n][n];
}
void lps(vector<int>& a)
{
    string X;
    for (int n : a)
    {
        //cout << "Int =" << n;
        if (n == 0)
        {
            X.push_back('0');
        }
        else if (n == 1)
        {
            X.push_back('1');
        }
        //cout << "String==" << X << endl;
    }
    int m = X.length();
    vector<vector<int>> lookup(m + 1, vector<int>(m + 1));
    string Y = X;
    reverse(Y.begin(), Y.end());
    cout << "\n\tThe length of the longest palindromic subsequence is " << LCSLength(X, Y, m, lookup) << endl;
    cout << "\n\tThe longest palindromic subsequence is " << findLongestPalindrome(X, Y, m, m, lookup)<<endl;
}

void draw(vector<int>& vo, vector<int>& vr, int bit, char* windowname)
{
    // Initialize GLFW
    glfwInit();

    // Tell GLFW what version of OpenGL we are using 
    // In this case we are using OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Tell GLFW we are using the CORE profile
    // So that means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFWwindow object of 1500 by 900 pixels, naming it "YoutubeOpenGL"
    GLFWwindow* window = glfwCreateWindow(1500, 900, windowname, NULL, NULL);
    // Error check if the window fails to create
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(1);
    }
    // Introduce the window into the current context
    glfwMakeContextCurrent(window);

    //Load GLAD so it configures OpenGL
    gladLoadGL();
    // Specify the viewport of OpenGL in the Window
    // In this case the viewport goes from x = 0, y = 0, to x = 1500, y = 900
    glViewport(0, 0, 1500, 900);



    // Create Vertex Shader Object and get its reference
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach Vertex Shader source to the Vertex Shader Object
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // Compile the Vertex Shader into machine code
    glCompileShader(vertexShader);

    // Create Fragment Shader Object and get its reference
    GLuint fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
    // Attach Fragment Shader source to the Fragment Shader Object
    glShaderSource(fragmentShader1, 1, &fragmentShaderSource, NULL);
    // Compile the Vertex Shader into machine code
    glCompileShader(fragmentShader1);

    GLuint fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2, 1, &fragmentShader2Source, NULL);
    glCompileShader(fragmentShader2);

    GLuint fragmentShader3 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader3, 1, &fragmentShader3Source, NULL);
    glCompileShader(fragmentShader3);

    // Create Shader Program Object and get its reference
    GLuint shaderProgram1 = glCreateProgram();
    // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(shaderProgram1, vertexShader);
    glAttachShader(shaderProgram1, fragmentShader1);
    // Wrap-up/Link all the shaders together into the Shader Program
    glLinkProgram(shaderProgram1);

    GLuint shaderProgram2 = glCreateProgram();
    glAttachShader(shaderProgram2, vertexShader);
    glAttachShader(shaderProgram2, fragmentShader2);
    glLinkProgram(shaderProgram2);

    GLuint shaderProgram3 = glCreateProgram();
    glAttachShader(shaderProgram3, vertexShader);
    glAttachShader(shaderProgram3, fragmentShader3);
    glLinkProgram(shaderProgram3);

    // Delete the now useless Vertex and Fragment Shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader1);
    glDeleteShader(fragmentShader2);
    glDeleteShader(fragmentShader3);
    
    vector<GLfloat> vertices;
    float gap = 0.055;
    //Axis
    vertices.push_back(1.0f);
    vertices.push_back(0.50f);
    vertices.push_back(-1.0f);
    vertices.push_back(0.50f);

    vertices.push_back(1.0f);
    vertices.push_back(-0.50f);
    vertices.push_back(-1.0f);
    vertices.push_back(-0.50f);

    vertices.push_back(-0.96);
    vertices.push_back(-1.0f);
    vertices.push_back(-0.96f);
    vertices.push_back(1.0f);

    int axis = vertices.size();
    //cout << axis<<endl;
    //Axis
    
    //Grid Lines
    vertices.push_back(1.0f);
    vertices.push_back(0.75f);
    vertices.push_back(-1.0f);
    vertices.push_back(0.75f);

    vertices.push_back(1.0f);
    vertices.push_back(0.25f);
    vertices.push_back(-1.0f);
    vertices.push_back(0.25f);

    vertices.push_back(1.0f);
    vertices.push_back(-0.25f);
    vertices.push_back(-1.0f);
    vertices.push_back(-0.25f);

    vertices.push_back(1.0f);
    vertices.push_back(-0.75f);
    vertices.push_back(-1.0f);
    vertices.push_back(-0.75f);


    for (float i = -1.0f + gap; i < 1; i=i+0.055)
    {
        vertices.push_back(i);
        vertices.push_back(-1.0f);
        
        vertices.push_back(i);
        vertices.push_back(1.0f);
    }
    int grid = vertices.size()-axis;

    //Grid Lines
    gap = 0.055;

    for (int i = 0; i < vo.size(); i++) {
        GLfloat val;
        if (vo[i] == -1)
        {
            val = 0.25f;
        }
        else if (vo[i] == 1)
        {
            val = 0.75f;
        }
        else
        {
            val = 0.5f;
        }

        vertices.push_back(-1.0f + gap);
        //cout << val << endl;
        vertices.push_back(val);
        gap = gap + 0.055;
        vertices.push_back(-1.0f + gap);
        vertices.push_back(val);
    }
    gap = 0.055;
    if (bit == 1) {
        for (int i = 0; i < vr.size(); i++) {
            GLfloat val;
            if (vr[i] == 1)
            {
                val = -0.25f;
            }
            else if (vr[i] == -1)
            {
                val = -0.75f;
            }
            else
            {
                val = -0.5f;
            }

            vertices.push_back(-1.0f + gap);
            //cout << val << endl;
            vertices.push_back(val);
            gap = gap + 0.055;
            vertices.push_back(-1.0f + gap);
            vertices.push_back(val);
        }
    }
    else if (bit == 2) {
        for (int i = 0; i < vr.size(); i++) {
            GLfloat val;
            if (vr[i] == 1)
            {
                val = -0.25f;
            }
            else if (vr[i] == -1)
            {
                val = -0.75f;
            }
            else
            {
                val = -0.5f;
            }

            vertices.push_back(-1.0f + gap);
            //cout << val << endl;
            vertices.push_back(val);
            gap = gap + (0.055/2);
            vertices.push_back(-1.0f + gap);
            vertices.push_back(val);
        }
    }

    //cout << vertices.size() << endl;
    

    // Vertices coordinates
    // Create reference containers for the Vartex Array Object and the Vertex Buffer Object
    GLuint VAO, VBO;

    // Generate the VAO and VBO with only 1 object each
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Make the VAO the current Vertex Array Object by binding it
    glBindVertexArray(VAO);

    // Bind the VBO specifying it's a GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Introduce the vertices into the VBO
    glBufferData(GL_ARRAY_BUFFER, vertices.size()* sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    // Enable the Vertex Attribute so that OpenGL knows to use it
    glEnableVertexAttribArray(0);

    // Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);



    // Main while loop
    while (!glfwWindowShouldClose(window))
    {

        // Specify the color of the background
        glClearColor(0.4382f, 0.3969f, 0.81f, 1.0f);
        // Clean the back buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);
        // Tell OpenGL which Shader Program we want to use
        glUseProgram(shaderProgram1);
        // Bind the VAO so OpenGL knows to use it
        glBindVertexArray(VAO);
        glLineWidth(3.0);
        glDrawArrays(GL_LINES, 0, axis/2);
        glUseProgram(shaderProgram3);
        glLineWidth(1.0);
        glDrawArrays(GL_LINES, axis/2,grid/2);
        glUseProgram(shaderProgram2);
        // Draw the triangle using the GL_TRIANGLES primitive
        glLineWidth(5.0);
        glDrawArrays(GL_LINE_STRIP, (axis+grid)/2, (vo.size()*2));
        glDrawArrays(GL_LINE_STRIP ,((axis + grid)/2)+vo.size() * 2, (vr.size() * 2));
        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // Take care of all GLFW events
        glfwPollEvents();
    }



    // Delete all the objects we've created
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram1);
    glDeleteProgram(shaderProgram2);

    // Delete window before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();
}
int main()
{
    string s;
    vector<int> vo, vr;
    int ch, l;
    cout << "Hello to Line Encoder:-\n\n"
        << "\t1:Choose Random Input\n\t2:Enter Your Own Input\n";
    cout << "->";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        cout << "Enter the lenght of input\n";
        cin >> l;
        cout << "Choose probability of 0 to 1\n1:50:50\n2:75:25\n3:With 4 or 8 consecutive zeros\n\n\tPress Any other key to Exit Program\n";
        int prob;
        cin >> prob;
        s = randomInput(l, prob);

        break;
    }
    case 2:
    {
        cout << "Input Unipolar NRZ data" << endl;
        cin >> s;
        break;
    }
    default:
    {
        cout << "Wrong input Exiting...\n";
        exit(1);
    }
    }
    cout << "\tFollowing is the NRZ data" << endl;
    vo = str2vect(s);
    cout << "\n\t";
    printvect(vo);
    lps(vo);
    while (true)
    {
    start:
        cout << "\nEnter the type of encoding you what:--\n\n"
            << "\t1:Polar->NRZ \n"
            << "\t2:Polar->RZ \n"
            << "\t3:Biphase\n"
            << "\t4:Bipolar(multilevel binary)\n"
            << "\t5:Block Coading\n"
            << "\t6:Scrambling AMI\n"
            << "\n\tPress Any other key to Exit Program\n";
        cout << "->";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            while (true)
            {
                cout << "\nEnter the type of NRZ encoding you what:--\n\n"
                    << "\t1:Polar NRZ-L Positive Logic {1='+1',0='-1'}\n"
                    << "\t2:Polar NRZ-L Negetive Logic {1='-1',0='+1'}\n"
                    << "\t3:Polar NRZ-I Negetive Logic {1='Invesion',0='No Change'}\n"
                    << "\t4:Polar NRZ-I Negetive Logic {1='No Change',0='Inversion'}\n"
                    << "\t5:Go to previous menu\n"
                    << "\n\tPress Any other key to Exit Program\n";
                cout << "->";
                cin >> l;
                switch (l)
                {
                case 1:
                {
                    vr = nrzl(0, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tNRZ-L Positive logic encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs NRZ-L Positive logic";
                    draw(vo,vr,1,name);
                    break;
                }
                case 2:
                {
                    vr = nrzl(1, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tNRZ-L Negetive logic encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs NRZ-L Negetive logic";
                    draw(vo, vr,1,name);
                    break;
                }
                case 3:
                {
                    vr = nrzi(0, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tNRZ-I Positive logic encoded data\n\t";
                    cout << "Start(1)->";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs NRZ-I Positive logic";
                    draw(vo, vr,1,name);
                    break;
                }
                case 4:
                {
                    vr = nrzi(1, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tNRZ-I Negetive logic encoded data\n\t";
                    cout << "Start(1)->";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs NRZ-I Negetive logic";
                    draw(vo, vr,1,name);
                    break;
                }
                case 5:
                {
                    goto start;
                }
                default:
                {
                    cout << "Wrong input Exiting...\n";
                    exit(1);
                }
                }
            }
        }
        case 2:
        {
            while (true)
            {
                cout << "\nEnter the type of RZ encoding you what:--\n\n"
                    << "\t1:Polar RZ Positive Logic {1='+10',0='-10'}\n"
                    << "\t2:Polar RZ Negetive Logic {1='-10',0='+10'}\n"
                    << "\t3:Go to previous menu\n"
                    << "\n\tPress Any other key to Exit Program\n";
                cin >> l;
                switch (l)
                {
                case 1:
                {
                    vr = rz(0, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tRZ Positive logic encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs RZ Positive logic";
                    draw(vo, vr, 2,name);
                    break;
                }
                case 2:
                {
                    vr = rz(1, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tRZ Negetive logic encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs RZ Negetive logic";
                    draw(vo, vr, 2,name);
                    break;
                }
                case 3:
                {
                    goto start;
                }
                default:
                {
                    cout << "Wrong input Exiting...\n";
                    exit(1);
                }
                }
            }
        }
        case 3:
        {
            while (true)
            {
                cout << "\nEnter the type of Biphase encoding you what:--\n\n"
                    << "\t1:Biphase Manchester(RZ + NRZ-L) {G.E. Thomas}->{1='+1-1',0='-1+1'}\n"
                    << "\t2:Biphase Manchester(RZ + NRZ-L) {IEEE 802.3}->{1='-1+1',0='+1-1'}\n"
                    <<"\t3:Biphase Differential Manchester(RZ + NRZ-I)->{1='Transition',0='No Transition'}\n"
                    <<"\t4:Biphase Differential Manchester(RZ + NRZ-I{Compliment})->{1='No Transition',0='Transition'}\n"
                    << "\t5:Go to previous menu\n"
                    << "\n\tPress Any other key to Exit Program\n";
                cin >> l;
                switch (l)
                {
                case 1:
                {
                    vr = manc(0, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tManchester encoded {G.E. Thomas} data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs Manchester {G.E. Thomas}";
                    draw(vo, vr, 2,name);
                    break;
                }
                case 2:
                {
                    vr = manc(1, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tManchester encoded {IEEE 802.3} data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs Manchester {IEEE 802.3}";
                    draw(vo, vr, 2,name);
                    break;
                }
                case 3:
                {
                    vr = dmanc(0, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tDifferential Manchester RZ + NRZ-I encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs Differential Manchester";
                    draw(vo, vr, 2,name);
                    break;
                }
                case 4:
                {
                    vr = dmanc(1, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tDifferential Manchester RZ + NRZ-I{Compliment} encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs Differential Manchester";
                    draw(vo, vr, 2,name);
                    break;
                }
                case 5:
                {
                    goto start;
                }
                default:
                {
                    cout << "Wrong input Exiting...\n";
                    exit(1);
                }
                }
            }
        }
        case 4:
        {
            while (true)
            {
                cout << "\nEnter the type of Bipolar(multilevel binary) encoding you what:--\n\n"
                    << "\t1:AMI (Alternate mark inversion)\n\t\t-> Neutral voltage represents 0 and 1 is represented by alternate + ve and -ve voltages\n"
                    << "\t2:Pseudoternary(converse of AMI)\n\t\t-> 1 represented by neutral and 0 by alternating levels\n"
                    << "\t3:Go to previous menu\n"
                    << "\n\tPress Any other key to Exit Program\n";
                cin >> l;
                switch (l)
                {
                case 1:
                {
                    vr = ami(0, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tAMI (Alternate mark inversion) encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs AMI";
                    draw(vo, vr, 1,name);
                    break;
                }
                case 2:
                {
                    vr = ami(1, vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\tPseudoternary(converse of AMI)encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs Pseudoternary";
                    draw(vo, vr, 1,name);
                    break;
                }
                case 3:
                {
                    goto start;
                }
                default:
                {
                    cout << "Wrong input Exiting...\n";
                    exit(1);
                }
                }
            }
        }
        case 5:
        {
            while (true)
            {
                cout << "\nEnter the type of Bipolar(multilevel binary) encoding you what:--\n\n"
                    << "\t1:4B/5B\n"
                    << "\t2:Go to previous menu\n"
                    << "\n\tPress Any other key to Exit Program\n";
                cin >> l;
                switch (l)
                {
                case 1:
                {
                    vr = b45(vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    cout << "\t4B/5B encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs 4B/5B";
                    draw(vo, vr, 1,name);
                    break;
                }
                case 2:
                {
                    goto start;
                }
                default:
                {
                    cout << "Wrong input Exiting...\n";
                    exit(1);
                }
                }
            }
        }
        case 6:
        {
            while (true)
            {
                cout << "\nEnter the type of Scrambled encoding you what:--\n\n"
                    << "\t1:B8ZS (Bipolar with 8 zero substitution)\n\t\t->Replace 8 consecutive zeros by 000VB0VB\n"
                    << "\t2:HDB3 (High density Bipolar 3 zero)\n\t\t->In this 4 consecutive zeros are replaced by 000V or B00V to maintain\n\t\t number of non - zero pulses after substitution\n"
                    << "\t3:Go to previous menu\n"
                    << "\n\tPress Any other key to Exit Program\n";
                cin >> l;
                switch (l)
                {
                case 1:
                {
                    vr = b8zs(vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    vector<int> temp = ami(0, vo);
                    cout << "\tAMI Encoaded Data\n\t";
                    printvect(temp);
                    cout << "\tB8ZS Encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs AMI";
                    draw(vo, temp, 1,name);
                    char name1[] = "Pranav's Line AMI Vs B8ZS";
                    draw(temp, vr, 1,name1);
                    break;
                }
                case 2:
                {
                    vr = hdb3(vo);
                    cout << "\tOriginal Data\n\t";
                    printvect(vo);
                    vector<int> temp = ami(0, vo);
                    cout << "\tAMI Encoaded Data\n\t";
                    printvect(temp);
                    cout << "\tHDB3 Encoded data\n\t";
                    printvect(vr);
                    char name[] = "Pranav's Line Encoder Original Vs AMI";
                    draw(vo, temp, 1, name);
                    char name1[] = "Pranav's Line AMI Vs HDB3";
                    draw(temp, vr, 1, name1);
                    break;
                }
                case 3:
                {
                    goto start;
                }
                default:
                {
                    cout << "Wrong input Exiting...\n";
                    exit(1);
                }
                }
            }
        }
        default:
        {
            cout << "Exiting...\nBye, Have a nice day \n";
            exit(1);
        }
        }
    }
}


