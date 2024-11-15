#include <iostream>
#include <string>
#include <vector>

class Estudiante {
public:
    std::string nombreEstudiante;
    std::string documentoEstudiante;

    Estudiante(std::string nombreEstudiante, std::string documentoEstudiante)
        : nombreEstudiante(nombreEstudiante), documentoEstudiante(documentoEstudiante) {
    }
};

class Curso {
public:
    std::string codigoCurso;
    std::string nombreCurso;

    Curso(std::string codigoCurso, std::string nombreCurso)
        : codigoCurso(codigoCurso), nombreCurso(nombreCurso) {
    }
};

class Sesion {
public:
    std::string fecha;
    std::string horaInicio;
    std::string horaFinal;
    std::string codigoCurso;
    int iterable;

    Sesion(std::string fecha, std::string horaInicio, std::string horaFinal, std::string codigoCurso,
           int iterable)
        : fecha(fecha), horaInicio(horaInicio), horaFinal(horaFinal), codigoCurso(codigoCurso),
          iterable(iterable) {
    }
};

class Asistencia {
public:
    int codigoSesion;
    std::string documentoEstudiante;
    int codigoAsistencia; // 1: Llego, 2: Llego Tarde, 3: NO LLEGO
    Asistencia(int codigoSesion, std::string documentoEstudiante, int codigoAsistencia)
        : codigoSesion(codigoSesion), documentoEstudiante(documentoEstudiante),
          codigoAsistencia(codigoAsistencia) {
    }
};

//Vectores con informacion para la realizacion de pruebas en terminal, esto no daña el funcionamiento

// Vector Estudiantes
std::vector<Estudiante> estudiantes = {
    Estudiante("Sebastian", "123"),
    Estudiante("Alejandro", "456"),
    Estudiante("Diego", "789"),
    Estudiante("Bryan", "147")
};
// Vector Cursos
std::vector<Curso> cursos = {
    Curso("H1", "Arquitectura")
};
// Vector Sesiones
std::vector<Sesion> sesiones = {
    Sesion("31/10/2024", "10:00", "12:00", "H1", 1),
    Sesion("01/11/2024", "14:00", "16:00", "H1", 2)
};
// Vector Asistencias
std::vector<Asistencia> asistencias = {
    Asistencia(1, "123", 1), // Sebastián llegó
    Asistencia(1, "456", 2) // Alejandro llegó tarde
};
// Vector Inscripciones
std::vector<std::pair<std::string, std::string> > inscripciones = {
    std::make_pair("123", "H1"),
    std::make_pair("456", "H1"),
    std::make_pair("789", "H1"),
    std::make_pair("147", "H1")
};
// Vector estudiantes NO LLEGARON
std::vector<std::string> estudiantesNoLlegaron;

int main() {
    int opcion;
    do {
        std::cout << "\n _- Menu -_ " << std::endl;
        std::cout << "1. Registrar un estudiante" << std::endl;
        std::cout << "2. Consultar los datos de un estudiante" << std::endl;
        std::cout << "3. Registrar curso" << std::endl;
        std::cout << "4. Consultar los datos de un curso" << std::endl;
        std::cout << "5. Registrar un estudiante a un curso" << std::endl;
        std::cout << "6. Consultar el listado de estudiantes a un curso" << std::endl;
        std::cout << "7. Registrar una sesion" << std::endl;
        std::cout << "8. Consultar los datos de una sesion" << std::endl;
        std::cout << "9. Registrar asistencia" << std::endl;
        std::cout << "10. Registrar estudiantes NO LLEGO" << std::endl;
        std::cout << "11. Consultar cuantos estudiantes NO LLEGARON" << std::endl;
        std::cout << "12. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                // Registrar estudiante
                std::string nombre, documento;
                std::cout << "Ingrese el nombre del estudiante: ";
                std::cin >> nombre;
                std::cout << "Ingrese el documento del estudiante: ";
                std::cin >> documento;
                estudiantes.emplace_back(nombre, documento);
                std::cout << "Estudiante registrado con exito." << std::endl;
                break;
            }
            case 2: {
                // Consultar estudiante
                std::string documento;
                std::cout << "Ingrese el documento del estudiante: ";
                std::cin >> documento;
                bool estudianteEncontrado = false;
                for (int i = 0; i < estudiantes.size(); i++) {
                    if (estudiantes[i].documentoEstudiante == documento) {
                        std::cout << "Nombre: " << estudiantes[i].nombreEstudiante << " , Documento: "
                                << estudiantes[i].documentoEstudiante << std::endl;
                        estudianteEncontrado = true;
                        break;
                    }
                }

                if (!estudianteEncontrado) {
                    std::cout << "Estudiante no encontrado." << std::endl;
                }
                break;
            }
            case 3: {
                // Registrar curso
                std::string codigo, nombre;
                std::cout << "Ingrese el codigo del curso: ";
                std::cin >> codigo;
                std::cout << "Ingrese el nombre del curso: ";
                std::cin >> nombre;
                cursos.emplace_back(Curso(codigo, nombre));
                std::cout << "Curso registrado con exito." << std::endl;
                break;
            }
            case 4: {
                // Consultar curso
                std::string codigo;
                std::cout << "Ingrese el codigo del curso: ";
                std::cin >> codigo;
                bool cursoEncontrado = false;
                for (int i = 0; i < cursos.size(); i++) {
                    if (cursos[i].codigoCurso == codigo) {
                        std::cout << "Codigo: " << cursos[i].codigoCurso << ", Nombre: " <<
                                cursos[i].nombreCurso << std::endl;
                        cursoEncontrado = true;
                        break;
                    }
                }
                if (!cursoEncontrado) {
                    std::cout << "Curso no encontrado." << std::endl;
                }
                break;
            }
            case 5: {
                // Registrar un estudiante a un curso
                std::string documentoEstudiante, codigoCurso;
                std::cout << "Ingrese el documento del estudiante: ";
                std::cin >> documentoEstudiante;
                std::cout << "Ingrese el codigo del curso: ";
                std::cin >> codigoCurso;
                inscripciones.emplace_back(documentoEstudiante, codigoCurso);
                std::cout << "Estudiante inscrito en el curso con exito." << std::endl;
                break;
            }
            case 6: {
                // Consultar el listado de estudiantes a un curso
                std::string codigoCurso;
                std::cout << "Ingrese el codigo del curso: ";
                std::cin >> codigoCurso;
                bool encontrado = false;
                for (int i = 0; i < inscripciones.size(); i++) {
                    if (inscripciones[i].second == codigoCurso) {
                        encontrado = true;
                        for (int x = 0; x < estudiantes.size(); x++) {
                            if (estudiantes[x].documentoEstudiante == inscripciones[i].first) {
                                std::cout << "- " << estudiantes[x].nombreEstudiante << " , Documento: " <<
                                        estudiantes[x].documentoEstudiante << std::endl;
                                break;
                            }
                        }
                    }
                }
                if (!encontrado) {
                    std::cout << "No hay estudiantes inscritos en este curso." << std::endl;
                }
                break;
            }
            case 7: {
                // Registrar sesion
                std::string fecha, horaInicio, horaFinal, codigoCurso;
                std::cout << "Ingrese el codigo del curso: ";
                std::cin >> codigoCurso;
                std::cout << "Ingrese la fecha de la sesion (DD/MM/YYYY): ";
                std::cin >> fecha;
                std::cout << "Ingrese la hora de inicio de la sesion (HH:MM): ";
                std::cin >> horaInicio;
                std::cout << "Ingrese la hora final de la sesion (HH:MM): ";
                std::cin >> horaFinal;
                // Crear una nueva sesión
                int nuevoCodigoSesion = sesiones.size() + 1; // Incrementar el código de sesión
                sesiones.emplace_back(fecha, horaInicio, horaFinal, codigoCurso,
                                      nuevoCodigoSesion);
                std::cout << "Sesion registrada con exito para el curso " << codigoCurso << "." <<
                        std::endl;
                break;
            }
            case 8: {
                // Consultar sesiones de un curso
                std::string codigoCurso;
                std::cout << "Ingrese el codigo del curso para las sesiones: ";
                std::cin >> codigoCurso;
                bool encontrado = false;
                for (int i = 0; i < sesiones.size(); i++) {
                    if (sesiones[i].codigoCurso == codigoCurso) {
                        std::cout << "Sesion encontrada: " << sesiones[i].fecha << ", " <<
                                sesiones[i].horaInicio << " - " << sesiones[i].horaFinal << std::endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    std::cout << "No hay sesiones para este curso." << std::endl;
                }
                break;
            }
            case 9: {
                // Registrar asistencia
                std::string documentoEstudiante;
                int codigoSesion, estado;
                std::cout << "Ingrese el documento del estudiante: ";
                std::cin >> documentoEstudiante;
                std::cout << "Ingrese el codigo de la sesion: ";
                std::cin >> codigoSesion;
                std::cout << "Ingrese el estado de asistencia (1: Llego, 2: Llego Tarde): ";
                std::cin >> estado;
                asistencias.emplace_back(codigoSesion, documentoEstudiante, estado);
                std::cout << "Asistencia registrada con exito." << std::endl;
                break;
            }
            case 10: {
                // Registrar estudiantes NO LLEGO
                estudiantesNoLlegaron.clear();
                for (const auto &inscripcion: inscripciones) {
                    std::string documentoEstudiante = inscripcion.first;
                    std::string codigoCurso = inscripcion.second;
                    // Comprobar si el estudiante tiene asistencia registrada en el curso
                    bool estudianteLlego = false;
                    for (const auto &asistencia: asistencias) {
                        if (asistencia.documentoEstudiante == documentoEstudiante &&
                            asistencia.codigoAsistencia != 3) {
                            estudianteLlego = true;
                            break;
                        }
                    }
                    if (!estudianteLlego) {
                        estudiantesNoLlegaron.push_back(documentoEstudiante);
                    }
                }
                std::cout << "Los estudiantes que NO LLEGARON han sido registrados " << std::endl;
                break;
            }
            case 11: {
                // Consultar cuantos estudiantes NO LLEGARON
                for (int i = 0; i < asistencias.size(); i++) {
                    if (asistencias[i].codigoAsistencia == 3) {
                        estudiantesNoLlegaron.push_back(asistencias[i].documentoEstudiante);
                    }
                }
                if (!estudiantesNoLlegaron.empty()) {
                    std::cout << "NO LLEGARON " << estudiantesNoLlegaron.size() << " ESTUDIANTES:"
                            << std::endl;
                    for (const auto &documento: estudiantesNoLlegaron) {
                        std::cout << "Documento: " << documento << std::endl;
                    }
                } else {
                    std::cout << "Todos los estudiantes llegaron a la asistencia." << std::endl;
                }
                break;
            }
            case 12: {
                std::cout << "Finalizando ejecucion... Hasta pronto" << std::endl;
                break;
            }
            default: {
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
            }
        }
    } while (opcion != 12);
    return 0;
}
