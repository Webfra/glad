#include <glad.hpp>

#include <iostream>

//========================================================================
void logOpenGlMessage(
        GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar* message,
        const void* userParam )
{
    (void) length;
    (void) userParam;
    using namespace std;
    cout << "---------------------opengl-callback-start------------" << endl;
    cout << "message: "<< message << endl;
    cout << "source:  ";

    switch(source)
    {
    case GL_DEBUG_SOURCE_API:
        cout << "GL_DEBUG_SOURCE_API";
        break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        cout << "GL_DEBUG_SOURCE_WINDOW_SYSTEM";
        break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        cout << "GL_DEBUG_SOURCE_SHADER_COMPILER";
        break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        cout << "GL_DEBUG_SOURCE_THIRD_PARTY";
        break;
    case GL_DEBUG_SOURCE_APPLICATION:
        cout << "GL_DEBUG_SOURCE_APPLICATION";
        break;
    case GL_DEBUG_SOURCE_OTHER:
        cout << "GL_DEBUG_SOURCE_OTHER";
        break;
    default:
        cout << "UNKOWN (" << source << ")";
        break;
    }
    cout << endl;

    cout << "type:    " ;
    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        cout << "ERROR";
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        cout << "DEPRECATED_BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        cout << "UNDEFINED_BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        cout << "PORTABILITY";
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        cout << "PERFORMANCE";
        break;
    case GL_DEBUG_TYPE_OTHER:
        cout << "OTHER";
        break;
    default:
        cout << "UNKOWN (" << type << ")";
        break;
    }
    cout << endl;

    cout << "id: " << id << endl;
    cout << "severity: ";

    switch (severity){
    case GL_DEBUG_SEVERITY_LOW:
        cout << "LOW";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        cout << "MEDIUM";
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        cout << "HIGH";
        break;
    }
    cout << endl;

    cout << "---------------------opengl-callback-end--------------" << endl;
}

//========================================================================
void APIENTRY openglCallbackFunction(GLenum source,
                                           GLenum type,
                                           GLuint id,
                                           GLenum severity,
                                           GLsizei length,
                                           const GLchar* message,
                                           const void* userParam){
    auto throw_an_exception { false };
    auto show_log { true };

    if( id == 131185 ) return;

    if( severity == GL_DEBUG_SEVERITY_HIGH )
        show_log = true;

    if( (type == GL_DEBUG_TYPE_ERROR) || (type == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR) )
        throw_an_exception = false;

    if(show_log)
        logOpenGlMessage(source, type, id, severity, length, message, userParam);

    if(throw_an_exception)
        throw std::runtime_error("OpenGL DEBUG Callback!");
}

//========================================================================
glad::glad(::GLADloadproc loadproc)
{
    auto glad_ok { ::gladLoadGLLoader(loadproc) };
    if( !glad_ok )
    {
        throw glad_exception("***ERROR: ::gladLoadGLLoader() failed!", __LINE__, __FILE__);
    }

#if 1 || defined(_DEBUG)

    ::glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    if( glDebugMessageCallback )
    {
        ::glDebugMessageCallback(openglCallbackFunction, nullptr);
        GLuint unusedIds = 0;
        ::glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DEBUG_TYPE_ERROR, GL_DEBUG_SEVERITY_HIGH, 0, nullptr, GL_TRUE);
        // std::cout << "OpenGL debug message control - unused IDs: " << unusedIds << std::endl;
    }
    else
    {
        std::cout << "glDebugMessageCallback not available!" << std::endl;
    }

#endif
}

//========================================================================
// End of file.
//========================================================================
